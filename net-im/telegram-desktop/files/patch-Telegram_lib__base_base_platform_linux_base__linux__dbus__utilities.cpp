--- Telegram/lib_base/base/platform/linux/base_linux_dbus_utilities.cpp.orig	2024-03-08 22:01:55 UTC
+++ Telegram/lib_base/base/platform/linux/base_linux_dbus_utilities.cpp
@@ -12,6 +12,7 @@ namespace base::Platform::DBus {
 namespace {
 
 using namespace gi::repository;
+namespace GObject = gi::repository::GObject;
 
 gi::result<XdgDBus::DBus> MakeInterface(const GDBusConnection *connection) {
 	return XdgDBus::DBusProxy::new_sync(
