--- ./chrome/browser/ui/views/frame/browser_view_layout.cc.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/frame/browser_view_layout.cc	2010-12-20 20:15:08.000000000 +0100
@@ -19,7 +19,7 @@
 #include "gfx/scrollbar_size.h"
 #include "views/window/window.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "views/window/hit_test.h"
 #endif
 
