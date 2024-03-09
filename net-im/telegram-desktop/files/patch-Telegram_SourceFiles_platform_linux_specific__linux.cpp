--- Telegram/SourceFiles/platform/linux/specific_linux.cpp.orig	2024-03-08 21:33:12 UTC
+++ Telegram/SourceFiles/platform/linux/specific_linux.cpp
@@ -55,6 +55,7 @@ https://github.com/telegramdesktop/tdesktop/blob/maste
 namespace {
 
 using namespace gi::repository;
+namespace GObject = gi::repository::GObject;
 namespace Gio = gi::repository::Gio;
 using namespace Platform;
 using Platform::internal::WaylandIntegration;
