--- chrome/browser/ui/views/frame/browser_view.cc.orig	2019-02-06 22:42:13.515085000 +0100
+++ chrome/browser/ui/views/frame/browser_view.cc	2019-02-06 22:43:58.340147000 +0100
@@ -1255,7 +1255,7 @@
 }
 
 void BrowserView::DestroyBrowser() {
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (quit_instruction_bubble_controller_) {
     GetWidget()->GetNativeView()->RemovePreTargetHandler(
         quit_instruction_bubble_controller_.get());
@@ -2089,7 +2089,7 @@
 }
 
 void BrowserView::OnWidgetDestroying(views::Widget* widget) {
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (quit_instruction_bubble_controller_) {
     GetWidget()->GetNativeView()->RemovePreTargetHandler(
         quit_instruction_bubble_controller_.get());
@@ -2435,7 +2435,7 @@
   GetWidget()->SetNativeWindowProperty(Profile::kProfileKey,
                                        browser_->profile());
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (browser_->SupportsWindowFeature(Browser::FEATURE_TOOLBAR)) {
     quit_instruction_bubble_controller_ =
         QuitInstructionBubbleController::GetInstance();
