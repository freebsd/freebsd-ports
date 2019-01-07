--- ui/message_center/public/cpp/message_center_constants.h.orig	2019-01-04 01:05:19.610265000 +0100
+++ ui/message_center/public/cpp/message_center_constants.h	2019-01-04 01:05:58.617215000 +0100
@@ -106,7 +106,7 @@
 const int kButtonIconTopPadding = 11;      // In DIPs.
 const int kButtonIconToTitlePadding = 16;  // In DIPs.
 
-#if !defined(OS_LINUX) || defined(USE_AURA)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(USE_AURA)
 constexpr SkColor kButtonSeparatorColor = SkColorSetRGB(234, 234, 234);
 constexpr SkColor kHoveredButtonBackgroundColor = SkColorSetRGB(243, 243, 243);
 #endif
