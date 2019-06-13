--- ui/views/corewm/tooltip_aura.cc.orig	2019-06-04 18:55:50 UTC
+++ ui/views/corewm/tooltip_aura.cc
@@ -35,7 +35,7 @@ constexpr int kCursorOffsetY = 15;
 
 // TODO(varkha): Update if native widget can be transparent on Linux.
 bool CanUseTranslucentTooltipWidget() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   return false;
 #else
   return true;
