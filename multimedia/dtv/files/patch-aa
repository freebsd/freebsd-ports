--- defs.h.orig	Mon Feb 11 04:14:17 2002
+++ defs.h	Sun Feb  1 20:01:30 2004
@@ -10,9 +10,17 @@
 #include <sys/mman.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#if __FreeBSD_version > 500000
+#include <dev/bktr/ioctl_bt848.h>
+#include <dev/bktr/ioctl_meteor.h>
+#else
 #include <machine/ioctl_bt848.h>
 #include <machine/ioctl_meteor.h>
-#include <machine/soundcard.h>
+#endif
+#endif
+#include <sys/soundcard.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdarg.h>
