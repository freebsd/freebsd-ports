--- chrome/browser/ui/views/autofill/popup/popup_base_view.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/ui/views/autofill/popup/popup_base_view.cc
@@ -135,7 +135,7 @@ class PopupBaseView::Widget : public views::Widget {
     // and setups is not consistent). This is not required for regular
     // Autofill popup use, but it makes certain attacks (those based on the
     // popup being obscured) less practical.
-    if constexpr (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)) {
+    if constexpr (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) {
       // On ChromeOS and Linux, `Activatable::kYes` and `kSecuritySurface` are
       // incompatible because `kSecuritySurface` windows force accelerated
       // desktop-level widgets (subsurfaces) which do not support reliable
