--- chrome/browser/ui/views/frame/browser_view.cc.orig	2019-03-11 22:00:54 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -1269,7 +1269,7 @@ void BrowserView::RotatePaneFocus(bool forwards) {
 }
 
 void BrowserView::DestroyBrowser() {
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (quit_instruction_bubble_controller_) {
     GetWidget()->GetNativeView()->RemovePreTargetHandler(
         quit_instruction_bubble_controller_.get());
@@ -2130,7 +2130,7 @@ views::View* BrowserView::CreateOverlayView() {
 }
 
 void BrowserView::OnWidgetDestroying(views::Widget* widget) {
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (quit_instruction_bubble_controller_) {
     GetWidget()->GetNativeView()->RemovePreTargetHandler(
         quit_instruction_bubble_controller_.get());
@@ -2474,7 +2474,7 @@ void BrowserView::InitViews() {
   GetWidget()->SetNativeWindowProperty(Profile::kProfileKey,
                                        browser_->profile());
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (browser_->SupportsWindowFeature(Browser::FEATURE_TOOLBAR)) {
     quit_instruction_bubble_controller_ =
         QuitInstructionBubbleController::GetInstance();
