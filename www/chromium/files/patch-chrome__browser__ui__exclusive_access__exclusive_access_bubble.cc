--- chrome/browser/ui/exclusive_access/exclusive_access_bubble.cc.orig	2015-04-14 18:31:21.000000000 -0400
+++ chrome/browser/ui/exclusive_access/exclusive_access_bubble.cc	2015-04-28 10:00:47.585758000 -0400
@@ -18,7 +18,7 @@
 
 // NOTE(koz): Linux doesn't use the thick shadowed border, so we add padding
 // here.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const int ExclusiveAccessBubble::kPaddingPx = 8;
 #else
 const int ExclusiveAccessBubble::kPaddingPx = 15;
