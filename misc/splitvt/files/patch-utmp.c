--- utmp.c.orig	Sat Jan 13 13:48:13 2001
+++ utmp.c	Wed Jun 18 04:45:38 2003
@@ -6,13 +6,14 @@
 #include	<fcntl.h>
 #include	<utmp.h>
 #include	<stdio.h>
+#include	<unistd.h>
 
 #ifdef DEBUG_UTMP
 #undef  UTMP_FILE
 #define UTMP_FILE  "/tmp/utmp"
 #else
 #ifndef UTMP_FILE
-#define UTMP_FILE  "/etc/utmp"
+#define UTMP_FILE _PATH_UTMP
 #endif /* UTMP_FILE */
 #endif /* DEBUG_UTMP */
 
