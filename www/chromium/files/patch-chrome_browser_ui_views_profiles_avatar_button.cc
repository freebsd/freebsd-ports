--- chrome/browser/ui/views/profiles/avatar_button.cc.orig	2018-06-13 00:10:08.000000000 +0200
+++ chrome/browser/ui/views/profiles/avatar_button.cc	2018-07-18 22:53:21.770071000 +0200
@@ -250,7 +250,7 @@
   } else if (apply_ink_drop) {
     SetInkDropMode(InkDropMode::ON);
     SetFocusPainter(nullptr);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     set_ink_drop_base_color(SK_ColorWHITE);
     SetBorder(std::make_unique<AvatarButtonThemedBorder>());
     generic_avatar_ =
@@ -544,7 +544,7 @@
 #endif
 }
 bool AvatarButton::ShouldApplyInkDrop() const {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   DCHECK_EQ(AvatarButtonStyle::THEMED, button_style_);
   return true;
 #elif defined(OS_MACOSX)
