--- chrome/browser/ui/libgtkui/nav_button_provider_gtk3.h.orig	2018-02-11 02:34:07.340548000 +0100
+++ chrome/browser/ui/libgtkui/nav_button_provider_gtk3.h	2018-02-11 02:32:04.747163000 +0100
@@ -31,7 +31,7 @@
 
  private:
   std::map<chrome::FrameButtonDisplayType,
-           gfx::ImageSkia[views::Button::STATE_COUNT]>
+           std::array<gfx::ImageSkia, views::Button::STATE_COUNT>>
       button_images_;
   std::map<chrome::FrameButtonDisplayType, gfx::Insets> button_margins_;
   gfx::Insets top_area_spacing_;
