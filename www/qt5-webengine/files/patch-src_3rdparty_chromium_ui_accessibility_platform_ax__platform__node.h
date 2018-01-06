--- src/3rdparty/chromium/ui/accessibility/platform/ax_platform_node.h.orig	2017-01-26 00:49:31 UTC
+++ src/3rdparty/chromium/ui/accessibility/platform/ax_platform_node.h
@@ -22,7 +22,7 @@
 #define PLATFORM_HAS_AX_PLATFORM_NODE_IMPL 1
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(USE_X11)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(USE_X11)
 #define PLATFORM_HAS_AX_PLATFORM_NODE_IMPL 1
 #endif
 
