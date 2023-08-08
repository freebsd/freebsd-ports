--- src/3rdparty/chromium/ui/views/corewm/tooltip_aura.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/views/corewm/tooltip_aura.cc
@@ -46,7 +46,7 @@ bool CanUseTranslucentTooltipWidget() {
 
 // TODO(varkha): Update if native widget can be transparent on Linux.
 bool CanUseTranslucentTooltipWidget() {
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN) || defined(OS_BSD)
   return false;
 #else
   return true;
