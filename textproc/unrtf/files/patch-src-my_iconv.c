diff -ruN src.old/my_iconv.c src/my_iconv.c
--- src.old/my_iconv.c	2009-08-10 14:02:54.000000000 +0600
+++ src/my_iconv.c	2009-08-10 14:03:26.000000000 +0600
@@ -10,6 +10,7 @@
 #include "malloc.h"
 #include "my_iconv.h"
 #include "util.h"
+#include "unicode.h"
 
 my_iconv_t
 my_iconv_open(const char *tocode, const char *fromcode)
