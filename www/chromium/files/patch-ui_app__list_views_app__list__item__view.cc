--- ui/app_list/views/app_list_item_view.cc.orig	2016-08-03 22:02:40.000000000 +0300
+++ ui/app_list/views/app_list_item_view.cc	2016-08-19 05:58:12.763965000 +0300
@@ -62,7 +62,7 @@
   const gfx::FontList& font_list = rb.GetFontList(kItemTextFontStyle);
 // The font is different on each platform. The font size is adjusted on some
 // platforms to keep a consistent look.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Reducing the font size by 2 makes it the same as the Windows font size.
   const int kFontSizeDelta = -2;
   return font_list.DeriveWithSizeDelta(kFontSizeDelta);
