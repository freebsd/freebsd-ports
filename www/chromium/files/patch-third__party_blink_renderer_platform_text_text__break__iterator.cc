--- third_party/blink/renderer/platform/text/text_break_iterator.cc.orig	2023-11-03 10:09:45 UTC
+++ third_party/blink/renderer/platform/text/text_break_iterator.cc
@@ -163,6 +163,8 @@ static const unsigned char kAsciiLineBreakTable[][(kAs
 
 #if U_ICU_VERSION_MAJOR_NUM >= 58
 #define BA_LB_COUNT (U_LB_COUNT - 3)
+#elif U_ICU_VERSION_MAJOR_NUM >= 74
+#define BA_LB_COUNT (U_LB_COUNT - 8)
 #else
 #define BA_LB_COUNT U_LB_COUNT
 #endif
