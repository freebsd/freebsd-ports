--- lib/randist/rand.c.orig	Sun Jul  1 02:45:44 2001
+++ lib/randist/rand.c	Sun Jul  1 02:46:03 2001
@@ -64,6 +64,7 @@
  *  struct timeb to be defined.  They can be
  *  found in timeb.h.
  */ 
+#include <sys/types.h>
 #include <sys/timeb.h>
 void 
 sl_randomize (void) 
