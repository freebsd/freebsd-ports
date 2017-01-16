--- third_party/WebKit/Source/platform/text/TextBreakIterator.cpp.orig	2016-12-13 00:53:03 UTC
+++ third_party/WebKit/Source/platform/text/TextBreakIterator.cpp
@@ -28,6 +28,9 @@
 #include "wtf/StdLibExtras.h"
 #include "wtf/text/CharacterNames.h"
 
+#include <unicode/uchar.h>
+#include <unicode/uvernum.h>
+
 namespace blink {
 
 unsigned numGraphemeClusters(const String& string) {
@@ -129,6 +132,11 @@ static const unsigned char asciiLineBrea
 };
 // clang-format on
 
+#if U_ICU_VERSION_MAJOR_NUM >= 58
+#define BA_LB_COUNT (U_LB_COUNT - 3)
+#else
+#define BA_LB_COUNT U_LB_COUNT
+#endif
 // Line breaking table for CSS word-break: break-all. This table differs from
 // asciiLineBreakTable in:
 // - Indices are Line Breaking Classes defined in UAX#14 Unicode Line Breaking
@@ -136,7 +144,7 @@ static const unsigned char asciiLineBrea
 // - 1 indicates additional break opportunities. 0 indicates to fallback to
 //   normal line break, not "prohibit break."
 // clang-format off
-static const unsigned char breakAllLineBreakClassTable[][U_LB_COUNT / 8 + 1] = {
+static const unsigned char breakAllLineBreakClassTable[][BA_LB_COUNT / 8 + 1] = {
     // XX AI AL B2 BA BB BK CB    CL CM CR EX GL HY ID IN    IS LF NS NU OP PO PR QU    SA SG SP SY ZW NL WJ H2    H3 JL JT JV CP CJ HL RI
     { B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0) }, // XX
     { B(0, 1, 1, 0, 1, 0, 0, 0), B(0, 0, 0, 0, 0, 1, 0, 0), B(0, 0, 0, 1, 1, 0, 1, 0), B(1, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 1, 0) }, // AI
@@ -190,7 +198,7 @@ static_assert(WTF_ARRAY_LENGTH(asciiLine
                   asciiLineBreakTableLastChar - asciiLineBreakTableFirstChar +
                       1,
               "asciiLineBreakTable should be consistent");
-static_assert(WTF_ARRAY_LENGTH(breakAllLineBreakClassTable) == U_LB_COUNT,
+static_assert(WTF_ARRAY_LENGTH(breakAllLineBreakClassTable) == BA_LB_COUNT,
               "breakAllLineBreakClassTable should be consistent");
 
 static inline bool shouldBreakAfter(UChar lastCh, UChar ch, UChar nextCh) {
@@ -226,8 +234,8 @@ static inline ULineBreak lineBreakProper
 
 static inline bool shouldBreakAfterBreakAll(ULineBreak lastLineBreak,
                                             ULineBreak lineBreak) {
-  if (lineBreak >= 0 && lineBreak < U_LB_COUNT && lastLineBreak >= 0 &&
-      lastLineBreak < U_LB_COUNT) {
+  if (lineBreak >= 0 && lineBreak < BA_LB_COUNT && lastLineBreak >= 0 &&
+      lastLineBreak < BA_LB_COUNT) {
     const unsigned char* tableRow = breakAllLineBreakClassTable[lastLineBreak];
     return tableRow[lineBreak / 8] & (1 << (lineBreak % 8));
   }
