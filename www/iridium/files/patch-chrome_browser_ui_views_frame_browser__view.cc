--- chrome/browser/ui/views/frame/browser_view.cc.orig	2025-10-28 14:29:43 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2463,7 +2463,7 @@ void BrowserView::ToolbarSizeChanged(bool is_animating
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   std::vector<ContentsWebView*> contents_web_views =
       GetAllVisibleContentsWebViews();
 
@@ -5954,7 +5954,7 @@ void BrowserView::MaybeShowProfileSwitchIPH() {
 }
 
 void BrowserView::MaybeShowSupervisedUserProfileSignInIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
