--- third_party/blink/renderer/platform/text/text_break_iterator.cc.orig	2025-12-06 09:30:09 UTC
+++ third_party/blink/renderer/platform/text/text_break_iterator.cc
@@ -102,6 +102,10 @@ static const unsigned char kBreakAllLineBreakClassTabl
     { B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0,  0, 0, 0, 0, 0, 0) }, // VF
     { B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0,  0, 0, 0, 0, 0, 0) }, // VI
 #endif  // U_ICU_VERSION_MAJOR_NUM >= 74
+#if U_ICU_VERSION_MAJOR_NUM >= 78
+    // Added in ICU 78. https://icu.unicode.org/download/78
+    { B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0,  0, 0, 0, 0, 0, 0) }, // UH
+#endif  // U_ICU_VERSION_MAJOR_NUM >= 78
 };
 // clang-format on
 
