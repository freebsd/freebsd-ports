--- ui/views/controls/button/label_button.cc.orig   Thu May 14 00:23:12 2015
+++ ui/views/controls/button/label_button.cc    Wed May 20 08:34:57 2015
@@ -17,7 +17,7 @@
 #include "ui/views/painter.h"
 #include "ui/views/window/dialog_delegate.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -26,7 +26,7 @@
 // The default spacing between the icon and text.
 const int kSpacing = 5;
 
-#if !(defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if !((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
 // Default text and shadow colors for STYLE_BUTTON.
 const SkColor kStyleButtonTextColor = SK_ColorBLACK;
 const SkColor kStyleButtonShadowColor = SK_ColorWHITE;
@@ -406,7 +406,7 @@
     // confusion. These details should either be pushed into ui::NativeThemeWin
     // or should be obsoleted by rendering buttons with paint calls instead of
     // with static assets. http://crbug.com/350498
-#if !(defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if !((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
     constant_text_color = true;
     colors[STATE_NORMAL] = kStyleButtonTextColor;
     label_->SetBackgroundColor(theme->GetSystemColor(
@@ -443,7 +443,7 @@
 
   scoped_ptr<LabelButtonBorder> label_button_border = CreateDefaultBorder();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   views::LinuxUI* linux_ui = views::LinuxUI::instance();
   if (linux_ui) {
     SetBorder(linux_ui->CreateNativeBorder(
