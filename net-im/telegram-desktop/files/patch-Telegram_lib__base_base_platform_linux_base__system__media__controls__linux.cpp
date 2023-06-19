--- Telegram/lib_base/base/platform/linux/base_system_media_controls_linux.cpp.orig	2023-06-03 03:29:41 UTC
+++ Telegram/lib_base/base/platform/linux/base_system_media_controls_linux.cpp
@@ -16,11 +16,12 @@
 #include <QtGui/QImage>
 #include <ksandbox.h>
 
-using namespace gi::repository;
-
 namespace base::Platform {
 
 namespace {
+
+using namespace gi::repository;
+namespace GObject = gi::repository::GObject;
 
 // QString to GLib::Variant.
 inline auto Q2V(const QString &s) {
