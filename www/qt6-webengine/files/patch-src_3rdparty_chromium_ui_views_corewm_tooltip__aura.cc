--- src/3rdparty/chromium/ui/views/corewm/tooltip_aura.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/views/corewm/tooltip_aura.cc
@@ -50,7 +50,7 @@ bool CanUseTranslucentTooltipWidget() {
 bool CanUseTranslucentTooltipWidget() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_WIN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
