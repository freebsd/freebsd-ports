--- unused-panels/user-accounts/um-utils.c.orig	2013-11-24 13:33:13.594698498 +0000
+++ unused-panels/user-accounts/um-utils.c	2013-11-24 13:33:34.715696820 +0000
@@ -25,7 +25,15 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <pwd.h>
-#include <utmp.h>
+#include <sys/param.h>
+#if __FreeBSD_version < 900000
+ #include <utmp.h>
+#else
+#include <utmpx.h>
+/* from the old utmp.h */
+#define UT_NAMESIZE 16
+#endif
+
 
 #include <glib.h>
 #include <glib/gi18n-lib.h>
