--- Telegram/lib_base/base/platform/linux/base_url_scheme_linux.cpp.orig	2024-03-08 21:53:47 UTC
+++ Telegram/lib_base/base/platform/linux/base_url_scheme_linux.cpp
@@ -22,6 +22,7 @@ namespace base::Platform {
 namespace {
 
 using namespace gi::repository;
+namespace GObject = gi::repository::GObject;
 
 void SnapDefaultHandler(const QString &protocol) {
     Snapcraft::SettingsProxy::new_for_bus(
