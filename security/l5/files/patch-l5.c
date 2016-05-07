--- l5.c.orig	1996-01-31 20:43:46 UTC
+++ l5.c
@@ -9,11 +9,6 @@
 #include <stdio.h>
 #include <fcntl.h>
 
-/* architecture dependencies?  XXX: UNTESTED -- someone?  please?? */
-#ifdef __alpha	/* XXX */
-#define long int
-#endif
-
 /* general portability stuff, somewhat sleazed from TW */
 #if (defined(SYSV) && (SYSV < 3))
 #include <limits.h>
