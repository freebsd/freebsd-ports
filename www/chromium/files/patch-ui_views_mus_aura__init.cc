--- ui/views/mus/aura_init.cc.orig	2017-06-05 19:03:30 UTC
+++ ui/views/mus/aura_init.cc
@@ -24,7 +24,7 @@
 #include "ui/views/style/typography_provider.h"
 #include "ui/views/views_delegate.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/font_service/public/cpp/font_loader.h"
 #endif
 
@@ -73,7 +73,7 @@ AuraInit::AuraInit(service_manager::Connector* connect
   InitializeResources(connector);
 
 // Initialize the skia font code to go ask fontconfig underneath.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   font_loader_ = sk_make_sp<font_service::FontLoader>(connector);
   SkFontConfigInterface::SetGlobal(font_loader_.get());
 #endif
@@ -86,7 +86,7 @@ AuraInit::AuraInit(service_manager::Connector* connect
 }
 
 AuraInit::~AuraInit() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (font_loader_.get()) {
     SkFontConfigInterface::SetGlobal(nullptr);
     // FontLoader is ref counted. We need to explicitly shutdown the background
