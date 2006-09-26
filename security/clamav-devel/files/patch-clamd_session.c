--- clamd/session.c.orig	Wed Sep 13 19:13:20 2006
+++ clamd/session.c	Tue Sep 26 09:42:41 2006
@@ -42,6 +42,10 @@
 #include <signal.h>
 #include <errno.h>
 #include <stddef.h>
+#if (defined(__FreeBSD__) && __FreeBSD_version >= 600000)
+#include <sys/limits.h>
+#endif
+#include <sys/syslimits.h>
 
 #include "libclamav/clamav.h"
 #include "libclamav/str.h"
