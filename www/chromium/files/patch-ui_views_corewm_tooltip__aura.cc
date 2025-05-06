--- ui/views/corewm/tooltip_aura.cc.orig	2025-05-05 10:57:53 UTC
+++ ui/views/corewm/tooltip_aura.cc
@@ -42,7 +42,7 @@ static constexpr int kTooltipMaxWidth = 800;
 
 // TODO(varkha): Update if native widget can be transparent on Linux.
 bool CanUseTranslucentTooltipWidget() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
