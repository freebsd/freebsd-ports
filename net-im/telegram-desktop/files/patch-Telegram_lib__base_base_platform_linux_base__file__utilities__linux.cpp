--- Telegram/lib_base/base/platform/linux/base_file_utilities_linux.cpp.orig	2024-03-08 22:07:09 UTC
+++ Telegram/lib_base/base/platform/linux/base_file_utilities_linux.cpp
@@ -30,6 +30,7 @@ namespace base::Platform {
 namespace {
 
 using namespace gi::repository;
+namespace GObject = gi::repository::GObject;
 
 void PortalShowInFolder(const QString &filepath, Fn<void()> fail) {
 	XdpOpenURI::OpenURIProxy::new_for_bus(
