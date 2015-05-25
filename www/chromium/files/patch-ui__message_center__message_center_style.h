--- ui/message_center/message_center_style.h.orig	2015-04-28 08:33:38.328173000 -0400
+++ ui/message_center/message_center_style.h	2015-04-28 08:34:12.794494000 -0400
@@ -102,7 +102,7 @@
 const int kButtonIconTopPadding = 11;      // In DIPs.
 const int kButtonIconToTitlePadding = 16;  // In DIPs.
 
-#if !defined(OS_LINUX) || defined(USE_AURA)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(USE_AURA)
 const SkColor kButtonSeparatorColor = SkColorSetRGB(234, 234, 234);
 const SkColor kHoveredButtonBackgroundColor = SkColorSetRGB(243, 243, 243);
 #endif
