--- ui/views/corewm/tooltip_aura.cc.orig	2016-12-16 15:15:24.020369000 +0000
+++ ui/views/corewm/tooltip_aura.cc	2016-12-16 15:16:03.296431000 +0000
@@ -34,7 +34,7 @@
 
 // TODO(varkha): Update if native widget can be transparent on Linux.
 bool CanUseTranslucentTooltipWidget() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   return false;
 #else
   return true;
