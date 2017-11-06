--- chrome/browser/ui/views/profiles/avatar_button.cc.orig	2017-09-05 21:05:14.000000000 +0200
+++ chrome/browser/ui/views/profiles/avatar_button.cc	2017-09-06 18:45:09.941798000 +0200
@@ -194,7 +194,7 @@
       label()->font_list().DeriveWithHeightUpperBound(kDisplayFontHeight));
 
   bool apply_ink_drop = IsCondensible();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   DCHECK_EQ(AvatarButtonStyle::THEMED, button_style);
   apply_ink_drop = true;
 #endif
@@ -202,7 +202,7 @@
   if (apply_ink_drop) {
     SetInkDropMode(InkDropMode::ON);
     SetFocusPainter(nullptr);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     constexpr int kIconSize = 16;
     set_ink_drop_base_color(SK_ColorWHITE);
     SetBorder(base::MakeUnique<AvatarButtonThemedBorder>());
