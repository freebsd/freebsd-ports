--- src/plugins/switch/cray_aries/switch_cray_aries.c.orig	2020-01-18 14:02:02 UTC
+++ src/plugins/switch/cray_aries/switch_cray_aries.c
@@ -43,7 +43,9 @@
 #include <fcntl.h>
 #include <inttypes.h>
 #include <limits.h>
+#ifdef __linux__
 #include <linux/limits.h>
+#endif
 #include <math.h>
 #include <sched.h>
 #include <signal.h>
