--- src/3rdparty/chromium/ui/views/corewm/tooltip_aura.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/views/corewm/tooltip_aura.cc
@@ -38,7 +38,7 @@ bool CanUseTranslucentTooltipWidget() {
 
 // TODO(varkha): Update if native widget can be transparent on Linux.
 bool CanUseTranslucentTooltipWidget() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
