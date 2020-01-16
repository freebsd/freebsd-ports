--- ui/gfx/font_util.cc.orig	2019-12-17 19:58:26 UTC
+++ ui/gfx/font_util.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <fontconfig/fontconfig.h>
 #include "ui/gfx/linux/fontconfig_util.h"
 #endif
@@ -24,11 +24,11 @@ void InitializeFonts() {
   // background (resources have not yet been granted to cast) since it prevents
   // the long delay the user would have seen on first rendering.
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Ensures the config is created on this thread.
   FcConfig* config = GetGlobalFontConfig();
   DCHECK(config);
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_BSD
 
 #if defined(OS_WIN)
   gfx::win::InitializeDirectWrite();
