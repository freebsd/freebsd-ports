--- chrome/browser/ui/views/tabs/tab.cc.orig	2019-10-21 19:06:24 UTC
+++ chrome/browser/ui/views/tabs/tab.cc
@@ -512,7 +512,7 @@ void Tab::OnMouseCaptureLost() {
 void Tab::OnMouseMoved(const ui::MouseEvent& event) {
   tab_style_->SetHoverLocation(event.location());
   controller_->OnMouseEventInTab(this, event);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   MaybeUpdateHoverStatus(event);
 #endif
 }
@@ -522,7 +522,7 @@ void Tab::OnMouseEntered(const ui::MouseEvent& event) 
 }
 
 void Tab::MaybeUpdateHoverStatus(const ui::MouseEvent& event) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Move the hit test area for hovering up so that it is not overlapped by tab
   // hover cards when they are shown.
   // TODO(crbug/978134): Once Linux/CrOS widget transparency is solved, remove
