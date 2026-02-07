--- core/UnicodeConverter/UnicodeConverter.cpp.orig	2025-10-13 15:33:25 UTC
+++ core/UnicodeConverter/UnicodeConverter.cpp
@@ -37,6 +37,7 @@
 #include "unicode/ucnv.h"     /* C   Converter API    */
 #include "unicode/usprep.h"
 
+#define TRUE 1
 #if !defined (_WIN32) && !defined (_WIN64)
 #if defined (_LINUX) && !defined(__ANDROID__) && !defined(_IOS) && !defined(_MAC)
 #define USE_ICONV
