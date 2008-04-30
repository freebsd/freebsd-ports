--- utmp.c.orig	2007-04-01 17:56:49.000000000 +0000
+++ utmp.c	2008-04-30 04:00:23.000000000 +0000
@@ -13,7 +13,7 @@
 #define UTMP_FILE  "/tmp/utmp"
 #else
 #ifndef UTMP_FILE
-#define UTMP_FILE  "/etc/utmp"
+#define UTMP_FILE _PATH_UTMP
 #endif /* UTMP_FILE */
 #endif /* DEBUG_UTMP */
 
