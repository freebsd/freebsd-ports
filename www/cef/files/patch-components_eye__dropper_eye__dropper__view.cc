--- components/eye_dropper/eye_dropper_view.cc.orig	2026-07-01 06:24:19 UTC
+++ components/eye_dropper/eye_dropper_view.cc
@@ -350,7 +350,7 @@ EyeDropperView::EyeDropperView(gfx::NativeView parent,
   contents_view->SetPreferredSize(contents_view->GetSize());
   delegate_->SetContentsView(std::move(contents_view));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use TYPE_MENU for Linux to ensure that the eye dropper view is displayed
   // above the color picker.
   views::Widget::InitParams params(
