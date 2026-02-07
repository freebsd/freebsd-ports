--- lib/randist/rand.c.orig	2016-06-20 13:16:43 UTC
+++ lib/randist/rand.c
@@ -64,6 +64,7 @@
  *  struct timeb to be defined.  They can be
  *  found in timeb.h.
  */ 
+#include <sys/types.h>
 #include <sys/timeb.h>
 void 
 sl_randomize (void) 
