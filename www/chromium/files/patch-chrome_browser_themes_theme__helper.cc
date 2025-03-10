--- chrome/browser/themes/theme_helper.cc.orig	2025-02-19 07:43:18 UTC
+++ chrome/browser/themes/theme_helper.cc
@@ -17,7 +17,7 @@
 #include "ui/gfx/image/image.h"
 #include "ui/native_theme/native_theme.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
