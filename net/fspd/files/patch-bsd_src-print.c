--- bsd_src/print.c.orig	2009-10-01 13:46:36.000000000 -0700
+++ bsd_src/print.c	2011-12-06 13:05:42.177765575 -0800
@@ -32,7 +32,11 @@
 #include <sys/param.h>
 #include <grp.h>
 #include <pwd.h>
+#if defined(__FreeBSD_version) && __FreeBSD_version > 900007
+#include <utmpx.h>
+#else
 #include <utmp.h>
+#endif
 #ifdef TIME_WITH_SYS_TIME
 #  include <sys/time.h>
 #  include <time.h>
