--- src/TRConfigLexer.re.orig	2012-03-03 19:17:45 UTC
+++ src/TRConfigLexer.re
@@ -72,7 +72,7 @@
 #define SC(cond)    LEXER_SC_ ## cond: LEXER_SC_ ## cond
 
 /* Check for end-of-input */
-#define CHECK_EOI()    if (_eoi) { return NULL; }
+#define CHECK_EOI()    if (_cursor >= _limit) { return NULL; }
 
 /* Skip a token */
 #define SKIP(cond)    CHECK_EOI(); goto LEXER_SC_ ## cond
@@ -115,10 +115,6 @@
 - (void) fill: (int) length {
     /* We just need to prevent re2c from walking off the end of our buffer */
     assert(_limit - _cursor >= 0);
-    if (_cursor == _limit) {
-        /* Save the cursor and signal EOI */
-        _eoi = _cursor;
-    }
 }
 
 - (TRConfigToken *) scan {
