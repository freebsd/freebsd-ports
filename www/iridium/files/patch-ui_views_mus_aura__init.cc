--- ui/views/mus/aura_init.cc.orig	2018-06-13 00:11:10.000000000 +0200
+++ ui/views/mus/aura_init.cc	2018-07-19 22:04:02.069063000 +0200
@@ -24,7 +24,7 @@
 #include "ui/views/style/typography_provider.h"
 #include "ui/views/views_delegate.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #include "ui/gfx/platform_font_linux.h"
 #endif
@@ -59,7 +59,7 @@
 }
 
 AuraInit::~AuraInit() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (font_loader_.get()) {
     SkFontConfigInterface::SetGlobal(nullptr);
     // FontLoader is ref counted. We need to explicitly shutdown the background
@@ -112,7 +112,7 @@
   }
 
 // Initialize the skia font code to go ask fontconfig underneath.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   font_loader_ = sk_make_sp<font_service::FontLoader>(connector);
   SkFontConfigInterface::SetGlobal(font_loader_.get());
 
