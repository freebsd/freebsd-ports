--- ui/message_center/message_center_style.h.orig	2017-04-19 19:06:54 UTC
+++ ui/message_center/message_center_style.h
@@ -121,7 +121,7 @@ const int kButtonHorizontalPadding = 16;
 const int kButtonIconTopPadding = 11;      // In DIPs.
 const int kButtonIconToTitlePadding = 16;  // In DIPs.
 
-#if !defined(OS_LINUX) || defined(USE_AURA)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(USE_AURA)
 const SkColor kButtonSeparatorColor = SkColorSetRGB(234, 234, 234);
 const SkColor kHoveredButtonBackgroundColor = SkColorSetRGB(243, 243, 243);
 #endif
