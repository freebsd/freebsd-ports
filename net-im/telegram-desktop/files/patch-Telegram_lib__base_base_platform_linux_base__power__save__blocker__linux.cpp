--- Telegram/lib_base/base/platform/linux/base_power_save_blocker_linux.cpp.orig	2024-03-08 22:11:02 UTC
+++ Telegram/lib_base/base/platform/linux/base_power_save_blocker_linux.cpp
@@ -26,6 +26,7 @@ namespace base::Platform {
 namespace {
 
 using namespace gi::repository;
+namespace GObject = gi::repository::GObject;
 
 #ifndef DESKTOP_APP_DISABLE_X11_INTEGRATION
 constexpr auto kResetScreenSaverTimeout = 10 * crl::time(1000);
