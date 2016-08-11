--- netcat.c.orig	2005-10-18 17:42:05 UTC
+++ netcat.c
@@ -48,9 +48,6 @@
 #else
 #include <malloc.h>
 #endif
-#ifdef HAVE_SELECT_H		/* random SV variants need this */
-#include <sys/select.h>
-#endif
 
 /* have to do this *before* including types.h. xxx: Linux still has it wrong */
 #ifdef FD_SETSIZE		/* should be in types.h, butcha never know. */
@@ -58,6 +55,12 @@
 #endif				/* fd's, something is horribly wrong! */
 #define FD_SETSIZE 16		/* <-- this'll give us a long anyways, wtf */
 #include <sys/types.h>		/* *now* do it.  Sigh, this is broken */
+#ifdef __FreeBSD__
+#include <inttypes.h>
+#endif
+#ifdef HAVE_SELECT_H           /* random SV variants need this */
+#include <sys/select.h>
+#endif
 
 #ifdef HAVE_RANDOM		/* aficionados of ?rand48() should realize */
 #define SRAND srandom		/* that this doesn't need *strong* random */
