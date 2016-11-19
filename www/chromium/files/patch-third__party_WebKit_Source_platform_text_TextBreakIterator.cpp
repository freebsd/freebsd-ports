https://chromium.googlesource.com/chromium/src.git/+/e60b571faa3f14dd9119a6792dccf12f8bf80192%5E%21/

--- third_party/WebKit/Source/platform/text/TextBreakIterator.cpp.orig	2016-08-03 19:02:36 UTC
+++ third_party/WebKit/Source/platform/text/TextBreakIterator.cpp
@@ -27,6 +27,9 @@
 #include "wtf/StdLibExtras.h"
 #include "wtf/text/CharacterNames.h"
 
+#include <unicode/uchar.h>
+#include <unicode/uvernum.h>
+
 namespace blink {
 
 unsigned numGraphemeClusters(const String& string)
@@ -123,13 +126,18 @@ static const unsigned char asciiLineBrea
     { B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), 0, B(0, 0, 0, 0, 0, 0, 0, 0), 0, 0, 0, B(0, 0, 0, 0, 0, 0, 0, 0), 0, 0, 0, B(0, 0, 0, 0, 0, 0, 0, 0) }, // DEL
 };
 
+#if U_ICU_VERSION_MAJOR_NUM >= 58
+#define BA_LB_COUNT (U_LB_COUNT - 3)
+#else
+#define BA_LB_COUNT U_LB_COUNT
+#endif
 // Line breaking table for CSS word-break: break-all. This table differs from
 // asciiLineBreakTable in:
 // - Indices are Line Breaking Classes defined in UAX#14 Unicode Line Breaking
 //   Algorithm: http://unicode.org/reports/tr14/#DescriptionOfProperties
 // - 1 indicates additional break opportunities. 0 indicates to fallback to
 //   normal line break, not "prohibit break."
-static const unsigned char breakAllLineBreakClassTable[][U_LB_COUNT / 8 + 1] = {
+static const unsigned char breakAllLineBreakClassTable[][BA_LB_COUNT / 8 + 1] = {
     // XX AI AL B2 BA BB BK CB    CL CM CR EX GL HY ID IN    IS LF NS NU OP PO PR QU    SA SG SP SY ZW NL WJ H2    H3 JL JT JV CP CJ HL RI
     { B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0) }, // XX
     { B(0, 1, 1, 0, 1, 0, 0, 0), B(0, 0, 0, 0, 0, 1, 0, 0), B(0, 0, 0, 1, 1, 0, 1, 0), B(1, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 1, 0) }, // AI
@@ -179,10 +187,10 @@ static const unsigned char breakAllLineB
 #undef AL
 
 static_assert(WTF_ARRAY_LENGTH(asciiLineBreakTable) == asciiLineBreakTableLastChar - asciiLineBreakTableFirstChar + 1, "asciiLineBreakTable should be consistent");
-static_assert(WTF_ARRAY_LENGTH(breakAllLineBreakClassTable) == U_LB_COUNT, "breakAllLineBreakClassTable should be consistent");
+static_assert(WTF_ARRAY_LENGTH(breakAllLineBreakClassTable) == BA_LB_COUNT,
+              "breakAllLineBreakClassTable should be consistent");
 
-static inline bool shouldBreakAfter(UChar lastCh, UChar ch, UChar nextCh)
-{
+static inline bool shouldBreakAfter(UChar lastCh, UChar ch, UChar nextCh) {
     // Don't allow line breaking between '-' and a digit if the '-' may mean a minus sign in the context,
     // while allow breaking in 'ABCD-1234' and '1234-5678' which may be in long URLs.
     if (ch == '-' && isASCIIDigit(nextCh))
@@ -210,10 +218,11 @@ static inline ULineBreak lineBreakProper
 
 static inline bool shouldBreakAfterBreakAll(ULineBreak lastLineBreak, ULineBreak lineBreak)
 {
-    if (lineBreak >= 0 && lineBreak < U_LB_COUNT && lastLineBreak >= 0 && lastLineBreak < U_LB_COUNT) {
-        const unsigned char* tableRow = breakAllLineBreakClassTable[lastLineBreak];
-        return tableRow[lineBreak / 8] & (1 << (lineBreak % 8));
-    }
+  if (lineBreak >= 0 && lineBreak < BA_LB_COUNT && lastLineBreak >= 0 &&
+      lastLineBreak < BA_LB_COUNT) {
+    const unsigned char* tableRow = breakAllLineBreakClassTable[lastLineBreak];
+    return tableRow[lineBreak / 8] & (1 << (lineBreak % 8));
+  }
     return false;
 }
 
