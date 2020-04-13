--- src/3rdparty/chromium/ui/views/corewm/tooltip_aura.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/ui/views/corewm/tooltip_aura.cc
@@ -41,7 +41,7 @@ constexpr int kVerticalPaddingBottom = 5;
 
 // TODO(varkha): Update if native widget can be transparent on Linux.
 bool CanUseTranslucentTooltipWidget() {
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN) || defined(OS_BSD)
   return false;
 #else
   return true;
