--- ui/views/controls/button/label_button.cc.orig	2016-05-11 19:02:36 UTC
+++ ui/views/controls/button/label_button.cc
@@ -30,7 +30,7 @@ namespace {
 // The default spacing between the icon and text.
 const int kSpacing = 5;
 
-#if !(defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if !((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
 // Default text and shadow colors for STYLE_BUTTON.
 const SkColor kStyleButtonTextColor = SK_ColorBLACK;
 const SkColor kStyleButtonShadowColor = SK_ColorWHITE;
@@ -482,7 +482,7 @@ void LabelButton::ResetColorsFromNativeT
     // confusion. These details should either be pushed into ui::NativeThemeWin
     // or should be obsoleted by rendering buttons with paint calls instead of
     // with static assets. http://crbug.com/350498
-#if !(defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if !((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
     constant_text_color = true;
     colors[STATE_NORMAL] = kStyleButtonTextColor;
     label_->SetBackgroundColor(theme->GetSystemColor(
