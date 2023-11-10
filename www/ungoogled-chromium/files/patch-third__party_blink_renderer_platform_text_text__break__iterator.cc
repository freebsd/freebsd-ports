--- third_party/blink/renderer/platform/text/text_break_iterator.cc.orig	2023-11-04 07:08:51 UTC
+++ third_party/blink/renderer/platform/text/text_break_iterator.cc
@@ -161,8 +161,12 @@ static const unsigned char kAsciiLineBreakTable[][(kAs
 };
 // clang-format on
 
-#if U_ICU_VERSION_MAJOR_NUM >= 58
+#if U_ICU_VERSION_MAJOR_NUM >= 74
+#define BA_LB_COUNT (U_LB_COUNT - 8)
+#elif U_ICU_VERSION_MAJOR_NUM >= 58
 #define BA_LB_COUNT (U_LB_COUNT - 3)
+#elif U_ICU_VERSION_MAJOR_NUM >= 74
+#define BA_LB_COUNT (U_LB_COUNT - 8)
 #else
 #define BA_LB_COUNT U_LB_COUNT
 #endif
