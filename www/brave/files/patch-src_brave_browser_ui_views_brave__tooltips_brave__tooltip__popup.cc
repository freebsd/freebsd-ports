--- src/brave/browser/ui/views/brave_tooltips/brave_tooltip_popup.cc.orig	2026-10-18 18:43:23 UTC
+++ src/brave/browser/ui/views/brave_tooltips/brave_tooltip_popup.cc
@@ -56,7 +56,8 @@ constexpr SkColor kBorderColor = SkColor
 constexpr int kCornerRadius = 0;
 #elif BUILDFLAG(IS_MAC)
 constexpr int kCornerRadius = 7;
-#elif BUILDFLAG(IS_LINUX)
+// No fallback branch, so without this kCornerRadius is undeclared on FreeBSD.
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr int kCornerRadius = 7;
 #endif
 
