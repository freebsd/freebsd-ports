--- chrome/browser/ui/views/frame/browser_view.cc.orig	2025-05-06 12:23:00 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2585,7 +2585,7 @@ void BrowserView::ToolbarSizeChanged(bool is_animating
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   GetContentsWebView()->SetFastResize(is_dragging);
   if (multi_contents_view_) {
     multi_contents_view_->GetInactiveContentsView()->SetFastResize(is_dragging);
@@ -5830,7 +5830,7 @@ void BrowserView::MaybeShowProfileSwitchIPH() {
 }
 
 void BrowserView::MaybeShowSupervisedUserProfileSignInIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
