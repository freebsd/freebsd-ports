--- l5.c.orig	Fri Nov 21 05:56:24 2003
+++ l5.c	Fri Nov 21 05:56:41 2003
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
