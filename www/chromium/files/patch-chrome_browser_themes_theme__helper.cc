--- chrome/browser/themes/theme_helper.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/themes/theme_helper.cc
@@ -29,7 +29,7 @@
 #include "chrome/browser/themes/browser_theme_pack.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
