--- ui/views/controls/button/label_button.cc.orig	2015-10-14 19:31:24.349106000 +0200
+++ ui/views/controls/button/label_button.cc	2015-10-14 19:35:30.925886000 +0200
@@ -23,7 +23,7 @@
 // The default spacing between the icon and text.
 const int kSpacing = 5;
 
-#if !(defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if !((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
 // Default text and shadow colors for STYLE_BUTTON.
 const SkColor kStyleButtonTextColor = SK_ColorBLACK;
 const SkColor kStyleButtonShadowColor = SK_ColorWHITE;
@@ -401,7 +401,7 @@
     // confusion. These details should either be pushed into ui::NativeThemeWin
     // or should be obsoleted by rendering buttons with paint calls instead of
     // with static assets. http://crbug.com/350498
-#if !(defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if !((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
     constant_text_color = true;
     colors[STATE_NORMAL] = kStyleButtonTextColor;
     label_->SetBackgroundColor(theme->GetSystemColor(
