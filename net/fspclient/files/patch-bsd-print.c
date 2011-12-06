--- bsd/print.c.orig	2009-09-15 13:34:20.000000000 -0700
+++ bsd/print.c	2011-12-06 13:16:42.300321971 -0800
@@ -27,7 +27,12 @@
 #include "client.h"
 #include <grp.h>
 #include <pwd.h>
+#include <sys/param.h>
+#if defined(__FreeBSD_version) && __FreeBSD_version > 900007
+#include <utmpx.h>
+#else
 #include <utmp.h>
+#endif
 #include <time.h>
 #include "ls.h"
 
