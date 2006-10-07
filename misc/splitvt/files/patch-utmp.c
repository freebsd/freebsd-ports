--- utmp.c.orig	Sat Jan 13 22:48:13 2001
+++ utmp.c	Sat Oct  7 14:35:08 2006
@@ -6,13 +6,15 @@
 #include	<fcntl.h>
 #include	<utmp.h>
 #include	<stdio.h>
+#include	<unistd.h>
+#include	<string.h>
 
 #ifdef DEBUG_UTMP
 #undef  UTMP_FILE
 #define UTMP_FILE  "/tmp/utmp"
 #else
 #ifndef UTMP_FILE
-#define UTMP_FILE  "/etc/utmp"
+#define UTMP_FILE _PATH_UTMP
 #endif /* UTMP_FILE */
 #endif /* DEBUG_UTMP */
 
