--- chrome/browser/ui/views/profiles/avatar_button.cc.orig	2018-02-24 16:25:10.000000000 +0100
+++ chrome/browser/ui/views/profiles/avatar_button.cc	2018-03-03 22:06:11.687961000 +0100
@@ -211,7 +211,7 @@
       label()->font_list().DeriveWithHeightUpperBound(kDisplayFontHeight));
 
   bool apply_ink_drop = IsCondensible();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   DCHECK_EQ(AvatarButtonStyle::THEMED, button_style);
   apply_ink_drop = true;
 #endif
@@ -229,7 +229,7 @@
   } else if (apply_ink_drop) {
     SetInkDropMode(InkDropMode::ON);
     SetFocusPainter(nullptr);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     set_ink_drop_base_color(SK_ColorWHITE);
     SetBorder(base::MakeUnique<AvatarButtonThemedBorder>());
     generic_avatar_ =
