--- lib/replace/libreplace.m4.orig	2009-09-30 07:24:50.000000000 -0500
+++ lib/replace/libreplace.m4	2010-09-24 16:55:12.000000000 -0500
@@ -98,3 +98,8 @@
 AC_CHECK_HEADERS(stdarg.h vararg.h)
-AC_CHECK_HEADERS(sys/mount.h mntent.h)
+AC_CHECK_HEADERS([sys/param.h sys/mount.h], [], [],
+[[#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+]])
+AC_CHECK_HEADERS(mntent.h)
 AC_CHECK_HEADERS(stropts.h)
