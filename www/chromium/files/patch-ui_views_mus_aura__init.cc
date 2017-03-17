--- ui/views/mus/aura_init.cc.orig	2017-03-09 20:04:49 UTC
+++ ui/views/mus/aura_init.cc
@@ -22,7 +22,7 @@
 #include "ui/views/mus/mus_client.h"
 #include "ui/views/views_delegate.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/font_service/public/cpp/font_loader.h"
 #endif
 
@@ -69,7 +69,7 @@ AuraInit::AuraInit(service_manager::Conn
   InitializeResources(connector);
 
 // Initialize the skia font code to go ask fontconfig underneath.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   font_loader_ = sk_make_sp<font_service::FontLoader>(connector);
   SkFontConfigInterface::SetGlobal(font_loader_.get());
 #endif
@@ -82,7 +82,7 @@ AuraInit::AuraInit(service_manager::Conn
 }
 
 AuraInit::~AuraInit() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (font_loader_.get()) {
     SkFontConfigInterface::SetGlobal(nullptr);
     // FontLoader is ref counted. We need to explicitly shutdown the background
