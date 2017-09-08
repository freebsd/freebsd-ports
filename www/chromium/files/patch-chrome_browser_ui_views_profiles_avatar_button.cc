--- chrome/browser/ui/views/profiles/avatar_button.cc.orig	2017-08-01 23:45:47.250068000 +0200
+++ chrome/browser/ui/views/profiles/avatar_button.cc	2017-08-01 23:46:19.223660000 +0200
@@ -171,7 +171,7 @@
       label()->font_list().DeriveWithHeightUpperBound(kDisplayFontHeight));
 
   bool apply_ink_drop = IsCondensible();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   DCHECK_EQ(AvatarButtonStyle::THEMED, button_style);
   apply_ink_drop = true;
 #endif
@@ -180,7 +180,7 @@
     SetInkDropMode(InkDropMode::ON);
     SetFocusPainter(nullptr);
     constexpr int kIconSize = 16;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     set_ink_drop_base_color(SK_ColorWHITE);
     SetBorder(base::MakeUnique<AvatarButtonThemedBorder>());
     generic_avatar_ = gfx::CreateVectorIcon(kProfileSwitcherOutlineIcon,
