--- chrome/browser/ui/views/frame/browser_view.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2450,7 +2450,7 @@ void BrowserView::ToolbarSizeChanged(bool is_animating
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   UpdateFastResizeForContentViews(is_dragging);
 
   if (!is_dragging) {
@@ -5832,7 +5832,7 @@ void BrowserView::MaybeShowProfileSwitchIPH() {
 }
 
 void BrowserView::MaybeShowSupervisedUserProfileSignInIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
@@ -5843,7 +5843,7 @@ void BrowserView::MaybeShowSupervisedUserProfileSignIn
 }
 
 void BrowserView::MaybeShowSignInBenefitsIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
