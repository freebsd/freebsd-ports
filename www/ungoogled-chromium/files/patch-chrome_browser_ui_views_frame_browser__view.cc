--- chrome/browser/ui/views/frame/browser_view.cc.orig	2025-09-22 06:25:21 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2130,10 +2130,6 @@ void BrowserView::ExitFullscreen() {
 void BrowserView::UpdateExclusiveAccessBubble(
     const ExclusiveAccessBubbleParams& params,
     ExclusiveAccessBubbleHideCallback first_hide_callback) {
-  if (base::CommandLine::ForCurrentProcess()->HasSwitch(
-          "hide-fullscreen-exit-ui"))
-    return;
-
   // Trusted pinned mode does not allow to escape. So do not show the bubble.
   bool is_trusted_pinned =
       platform_util::IsBrowserLockedFullscreen(browser_.get());
@@ -2480,7 +2476,7 @@ void BrowserView::ToolbarSizeChanged(bool is_animating
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   std::vector<ContentsWebView*> contents_web_views =
       GetAllVisibleContentsWebViews();
 
@@ -5163,7 +5159,6 @@ void BrowserView::AddedToWidget() {
 
   toolbar_->Init();
 
-  if (!base::CommandLine::ForCurrentProcess()->HasSwitch("remove-tabsearch-button"))
   if (GetIsNormalType()) {
     if (features::HasTabSearchToolbarButton()) {
       tab_search_bubble_host_ = std::make_unique<TabSearchBubbleHost>(
@@ -5977,7 +5972,7 @@ void BrowserView::MaybeShowProfileSwitchIPH() {
 }
 
 void BrowserView::MaybeShowSupervisedUserProfileSignInIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
