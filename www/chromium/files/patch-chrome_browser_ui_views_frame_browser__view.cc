--- chrome/browser/ui/views/frame/browser_view.cc.orig	2025-12-12 08:02:48 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2305,7 +2305,7 @@ void BrowserView::ToolbarSizeChanged(bool is_animating
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   std::vector<ContentsWebView*> contents_web_views =
       GetAllVisibleContentsWebViews();
 
@@ -5005,7 +5005,8 @@ int BrowserView::NonClientHitTest(const gfx::Point& po
 }
 
 gfx::Size BrowserView::GetMinimumSize() const {
-  return GetBrowserViewLayout()->GetMinimumSize(this);
+  auto* const layout = GetBrowserViewLayout();
+  return layout ? layout->GetMinimumSize(this) : gfx::Size();
 }
 
 ///////////////////////////////////////////////////////////////////////////////
@@ -5919,7 +5920,7 @@ void BrowserView::MaybeShowProfileSwitchIPH() {
 }
 
 void BrowserView::MaybeShowSupervisedUserProfileSignInIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
@@ -5929,7 +5930,7 @@ void BrowserView::MaybeShowSupervisedUserProfileSignIn
 }
 
 void BrowserView::MaybeShowSignInBenefitsIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
