--- chrome/browser/ui/views/frame/browser_view.cc.orig	2026-05-13 08:49:22 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2475,7 +2475,7 @@ void BrowserView::ToolbarSizeChanged(bool is_animating
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   UpdateFastResizeForContentViews(is_dragging);
 
   if (!is_dragging) {
@@ -6000,7 +6000,7 @@ void BrowserView::MaybeShowProfileSwitchIPH() {
 }
 
 void BrowserView::MaybeShowSupervisedUserProfileSignInIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
@@ -6010,7 +6010,7 @@ void BrowserView::MaybeShowSupervisedUserProfileSignIn
 }
 
 void BrowserView::MaybeShowSignInBenefitsIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
