--- ui/message_center/views/message_popup_view.cc.orig	2024-09-30 07:45:04 UTC
+++ ui/message_center/views/message_popup_view.cc
@@ -144,7 +144,7 @@ std::unique_ptr<views::Widget> MessagePopupView::Show(
   params.z_order = ui::ZOrderLevel::kFloatingWindow;
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Make the widget explicitly activatable as TYPE_POPUP is not activatable by
   // default but we need focus for the inline reply textarea.
   params.activatable = views::Widget::InitParams::Activatable::kYes;
