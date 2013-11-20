--- panels/user-accounts/um-utils.c.orig	2013-05-22 16:25:19.000000000 +0000
+++ panels/user-accounts/um-utils.c	2013-10-09 16:50:07.978760476 +0000
@@ -25,7 +25,15 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <pwd.h>
-#include <utmp.h>
+
+#include <sys/param.h>
+#if __FreeBSD_version < 900000
+ #include <utmp.h>
+#else
+#include <utmpx.h>
+/* from the old utmp.h */
+#define UT_NAMESIZE 16
+#endif
 
 #include <glib.h>
 #include <glib/gi18n-lib.h>
