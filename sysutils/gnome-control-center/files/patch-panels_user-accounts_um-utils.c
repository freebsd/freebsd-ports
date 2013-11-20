--- panels/user-accounts/um-utils.c.orig	2011-09-17 14:55:58.000000000 +0200
+++ panels/user-accounts/um-utils.c	2011-09-17 14:57:01.000000000 +0200
@@ -25,7 +25,16 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <pwd.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#if __FreeBSD_version < 900000
 #include <utmp.h>
+#else
+#include <utmpx.h>
+/* from the old utmp.h */
+#define UT_NAMESIZE 16
+#endif
+#endif
 
 #include <glib.h>
 #include <glib/gi18n.h>
