--- utmp.c.orig	Sun Jan 14 11:36:17 2001
+++ utmp.c	Sun Jan 14 11:38:25 2001
@@ -12,7 +12,7 @@
 #define UTMP_FILE  "/tmp/utmp"
 #else
 #ifndef UTMP_FILE
-#define UTMP_FILE  "/etc/utmp"
+#define UTMP_FILE _PATH_UTMP
 #endif /* UTMP_FILE */
 #endif /* DEBUG_UTMP */
 
