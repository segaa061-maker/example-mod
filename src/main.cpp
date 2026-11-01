#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        if (Mod::get()->getSettingValue<bool>("noclip")) return;
        PlayLayer::destroyPlayer(player, object);
    }
};

$execute {
    CCScheduler::get()->setTimeScale(
        static_cast<float>(Mod::get()->getSettingValue<double>("speed"))
    );
    listenForSettingChanges("speed", [](double value) {
        CCScheduler::get()->setTimeScale(static_cast<float>(value));
    });
}
