--- ui/accessibility/platform/ax_platform_node.h.orig	2016-03-05 14:51:09.738154122 +0100
+++ ui/accessibility/platform/ax_platform_node.h	2016-03-05 14:52:07.721568603 +0100
@@ -22,7 +22,7 @@
 #define PLATFORM_HAS_AX_PLATFORM_NODE_IMPL 1
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(USE_X11)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(USE_X11)
 #define PLATFORM_HAS_AX_PLATFORM_NODE_IMPL 1
 #endif
 
