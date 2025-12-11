--- chrome/browser/ui/test/test_browser_ui.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/ui/test/test_browser_ui.cc
@@ -21,7 +21,7 @@
 #include "ui/views/widget/widget.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/public/common/content_switches.h"
 #include "ui/base/test/skia_gold_matching_algorithm.h"
 #include "ui/compositor/compositor.h"
@@ -35,7 +35,7 @@
 #endif
 
 // TODO(crbug.com/40625383) support Mac for pixel tests.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define SUPPORTS_PIXEL_TEST
 #endif
 
