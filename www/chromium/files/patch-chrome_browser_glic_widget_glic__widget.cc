--- chrome/browser/glic/widget/glic_widget.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/glic/widget/glic_widget.cc
@@ -51,7 +51,7 @@
 #include "ui/views/win/hwnd_util.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #include "chrome/browser/ui/views/frame/opaque_browser_frame_view_layout.h"
 #endif
@@ -106,7 +106,7 @@ class GlicClientView : public views::ClientView {
   GlicView* glic_view() { return static_cast<GlicView*>(contents_view()); }
 };
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class GlicFrameView : public views::NativeFrameView {
  public:
   explicit GlicFrameView(views::Widget* widget)
@@ -125,7 +125,7 @@ class GlicFrameView : public views::NativeFrameView {
 #if BUILDFLAG(IS_WIN)
     int resize_border = resize_border =
         display::win::GetScreenWin()->GetSystemMetricsInDIP(SM_CXSIZEFRAME);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     int resize_border = OpaqueBrowserFrameViewLayout::kFrameBorderThickness;
 #endif
     const bool can_resize = GetWidget()->widget_delegate() &&
@@ -357,7 +357,7 @@ std::unique_ptr<views::WidgetDelegate> GlicWidget::Cre
         return std::make_unique<GlicClientView>(widget, contents_view);
       }));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   delegate->SetFrameViewFactory(base::BindRepeating(
       [](views::Widget* widget) -> std::unique_ptr<views::FrameView> {
         return std::make_unique<GlicFrameView>(widget);
@@ -433,7 +433,7 @@ std::unique_ptr<GlicWidget> GlicWidget::Create(views::
 #if BUILDFLAG(IS_MAC)
   params.animation_enabled = true;
 #endif  // BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   params.wm_class_class = shell_integration_linux::GetProgramClassClass();
   params.wayland_app_id = params.wm_class_class + "-glic";
 #endif  // BUILDFLAG(IS_LINUX)
