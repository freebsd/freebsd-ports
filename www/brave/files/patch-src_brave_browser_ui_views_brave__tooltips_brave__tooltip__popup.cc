--- src/brave/browser/ui/views/brave_tooltips/brave_tooltip_popup.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/browser/ui/views/brave_tooltips/brave_tooltip_popup.cc
@@ -54,7 +54,8 @@
 constexpr int kCornerRadius = 0;
 #elif BUILDFLAG(IS_MAC)
 constexpr int kCornerRadius = 7;
-#elif BUILDFLAG(IS_LINUX)
+// No fallback branch, so without this kCornerRadius is undeclared on FreeBSD.
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr int kCornerRadius = 7;
 #endif
 
