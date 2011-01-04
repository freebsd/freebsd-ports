--- lib/arithmetic_sse_double.h.orig	2010-12-30 02:13:34.000000000 +0800
+++ lib/arithmetic_sse_double.h	2010-12-30 02:14:04.000000000 +0800
@@ -26,9 +26,6 @@
 /* $Id$ */
 
 #include <stdlib.h>
-#ifndef __APPLE__
-#include <malloc.h>
-#endif
 #include <memory.h>
 
 #if     1400 <= _MSC_VER
