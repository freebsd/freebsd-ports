--- netcat.c.orig	Wed Nov  6 13:42:04 2002
+++ netcat.c	Wed Nov  6 13:47:27 2002
@@ -45,9 +45,6 @@
 #else
 #include <malloc.h>
 #endif
-#ifdef HAVE_SELECT_H		/* random SV variants need this */
-#include <sys/select.h>
-#endif
 
 /* have to do this *before* including types.h. xxx: Linux still has it wrong */
 #ifdef FD_SETSIZE		/* should be in types.h, butcha never know. */
@@ -55,6 +52,12 @@
 #endif				/* fd's, something is horribly wrong! */
 #define FD_SETSIZE 16		/* <-- this'll give us a long anyways, wtf */
 #include <sys/types.h>		/* *now* do it.  Sigh, this is broken */
+#ifdef __FreeBSD__
+#include <inttypes.h>
+#endif
+#ifdef HAVE_SELECT_H		/* random SV variants need this */
+#include <sys/select.h>
+#endif
 
 #ifdef HAVE_RANDOM		/* aficionados of ?rand48() should realize */
 #define SRAND srandom		/* that this doesn't need *strong* random */

