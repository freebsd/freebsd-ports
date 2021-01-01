--- ui/message_center/public/cpp/message_center_constants.h.orig	2019-06-04 18:55:50 UTC
+++ ui/message_center/public/cpp/message_center_constants.h
@@ -105,7 +105,7 @@ const int kButtonHorizontalPadding = 16;   // In DIPs.
 const int kButtonIconTopPadding = 11;      // In DIPs.
 const int kButtonIconToTitlePadding = 16;  // In DIPs.
 
-#if !defined(OS_LINUX) || defined(USE_AURA)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(USE_AURA)
 constexpr SkColor kButtonSeparatorColor = SkColorSetRGB(234, 234, 234);
 constexpr SkColor kHoveredButtonBackgroundColor = SkColorSetRGB(243, 243, 243);
 #endif
