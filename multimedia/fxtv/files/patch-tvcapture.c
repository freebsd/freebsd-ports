
$FreeBSD$

--- tvcapture.c.orig
+++ tvcapture.c
@@ -34,11 +34,18 @@
 #include <stdlib.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 #ifdef __NetBSD__
 # include <dev/ic/bt8xx.h>
+#endif
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#if __FreeBSD_version > 500000
+#include <dev/bktr/ioctl_bt848.h>
 #else
-# include <machine/ioctl_bt848.h>
+#include <machine/ioctl_bt848.h>
+#endif
 #endif
 #include <signal.h>
 #include <sys/ioctl.h>
