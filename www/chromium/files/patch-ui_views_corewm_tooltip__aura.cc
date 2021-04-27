--- ui/views/corewm/tooltip_aura.cc.orig	2021-04-14 18:41:39 UTC
+++ ui/views/corewm/tooltip_aura.cc
@@ -51,7 +51,7 @@ constexpr int kVerticalPaddingBottom = 5;
 bool CanUseTranslucentTooltipWidget() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_WIN)
+#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_WIN) || defined(OS_BSD)
   return false;
 #else
   return true;
