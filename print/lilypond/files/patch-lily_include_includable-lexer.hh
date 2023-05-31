--- lily/include/includable-lexer.hh.orig	2023-02-10 17:44:03 UTC
+++ lily/include/includable-lexer.hh
@@ -21,7 +21,7 @@
 #define INCLUDABLE_LEXER_HH
 
 #ifndef LEXER_CC
-#include <FlexLexer.h>
+#include "/usr/include/FlexLexer.h"
 #endif
 
 #include "std-string.hh"
