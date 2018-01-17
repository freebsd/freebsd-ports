--- src/3rdparty/chromium/ui/message_center/message_center_style.h.orig	2017-01-26 00:49:32 UTC
+++ src/3rdparty/chromium/ui/message_center/message_center_style.h
@@ -115,7 +115,7 @@ const int kButtonHorizontalPadding = 16;
 const int kButtonIconTopPadding = 11;      // In DIPs.
 const int kButtonIconToTitlePadding = 16;  // In DIPs.
 
-#if !defined(OS_LINUX) || defined(USE_AURA)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(USE_AURA)
 const SkColor kButtonSeparatorColor = SkColorSetRGB(234, 234, 234);
 const SkColor kHoveredButtonBackgroundColor = SkColorSetRGB(243, 243, 243);
 #endif
