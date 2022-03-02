--- ui/views/corewm/tooltip_aura.cc.orig	2022-02-28 16:54:41 UTC
+++ ui/views/corewm/tooltip_aura.cc
@@ -50,7 +50,7 @@ constexpr int kVerticalPaddingBottom = 5;
 bool CanUseTranslucentTooltipWidget() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_WIN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
