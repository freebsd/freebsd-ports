--- Telegram/SourceFiles/platform/linux/integration_linux.cpp.orig	2024-03-08 23:40:11 UTC
+++ Telegram/SourceFiles/platform/linux/integration_linux.cpp
@@ -27,6 +27,7 @@ namespace Platform {
 namespace {
 
 using namespace gi::repository;
+namespace GObject = gi::repository::GObject;
 
 class Application : public Gio::impl::ApplicationImpl {
 public:
