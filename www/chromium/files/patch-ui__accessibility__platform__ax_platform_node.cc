--- ui/accessibility/platform/ax_platform_node.cc.orig	2015-05-21 15:15:07.691444000 -0400
+++ ui/accessibility/platform/ax_platform_node.cc	2015-05-21 15:15:32.121315000 -0400
@@ -9,7 +9,7 @@
 
 namespace ui {
 
-#if !defined(OS_MACOSX) && !defined(OS_WIN) && !(defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if !defined(OS_MACOSX) && !defined(OS_WIN) && !(defined(OS_LINUX) && !defined(OS_CHROMEOS)) && !defined(OS_BSD)
 // static
 AXPlatformNode* AXPlatformNode::Create(AXPlatformNodeDelegate* delegate) {
   return nullptr;
