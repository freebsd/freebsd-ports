--- src/miscencdec.c.orig	2016-02-26 15:58:08 UTC
+++ src/miscencdec.c
@@ -31,7 +31,7 @@
 #endif
 
 #include "misc.h"
-#include "md5.h"
+#include <md5.h>
 
 
 /* To understand why the URLDecode*() and URLEncode*() functions are coded this way see README.URL */
