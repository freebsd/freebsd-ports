--- audioplugin/MP3/audioencoder/lame3.70/lame.c.orig	Fri Jul 27 19:53:34 2001
+++ audioplugin/MP3/audioencoder/lame3.70/lame.c	Mon Jul  2 10:31:21 2007
@@ -47,6 +47,9 @@
 #include "asmstuff.h"
 #endif
 
+#ifdef __FreeBSD__
+#include <floatingpoint.h>
+#endif
 
 /* Global variable definitions for lame.c */
 static Bit_stream_struc   bs;
@@ -1198,7 +1201,6 @@
    *  Disable floating point exepctions
    */
 #ifdef __FreeBSD__
-# include <floatingpoint.h>
   {
   /* seet floating point mask to the Linux default */
   fp_except_t mask;
