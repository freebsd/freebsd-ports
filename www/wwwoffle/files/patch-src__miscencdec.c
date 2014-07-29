--- src/miscencdec.c.orig	Sun Nov 18 11:39:53 2001
+++ src/miscencdec.c	Tue Feb 26 21:03:13 2002
@@ -35,7 +35,7 @@
 #endif
 
 #include "misc.h"
-#include "md5.h"
+#include <md5.h>
 
 
 /* To understand why the URLDecode*() and URLEncode*() functions are coded this way see README.URL */
