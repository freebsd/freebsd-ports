--- lib/audioencoder/lame3.70/lame.c.orig	Tue Sep 12 18:12:24 2000
+++ lib/audioencoder/lame3.70/lame.c	Mon Jul  2 22:17:43 2007
@@ -46,6 +46,9 @@
 #include "asmstuff.h"
 #endif
 
+#ifdef __FreeBSD__
+#include <floatingpoint.h>
+#endif
 
 /* Global variable definitions for lame.c */
 static Bit_stream_struc   bs;
@@ -1197,7 +1200,6 @@
    *  Disable floating point exepctions
    */
 #ifdef __FreeBSD__
-# include <floatingpoint.h>
   {
   /* seet floating point mask to the Linux default */
   fp_except_t mask;
