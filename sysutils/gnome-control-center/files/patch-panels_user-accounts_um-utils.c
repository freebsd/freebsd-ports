--- panels/user-accounts/um-utils.c.orig	2014-03-03 11:55:25.000000000 +0000
+++ panels/user-accounts/um-utils.c	2014-03-15 15:23:03.820288215 +0000
@@ -26,6 +26,16 @@
 #include <limits.h>
 #include <unistd.h>
 #include <pwd.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#if __FreeBSD_version < 900000
+#include <utmp.h>
+#else
+#include <utmpx.h>
+/* from the old utmp.h */
+#define UT_NAMESIZE 16
+#endif
+#endif
 
 #include <gio/gio.h>
 #include <gio/gunixoutputstream.h>
