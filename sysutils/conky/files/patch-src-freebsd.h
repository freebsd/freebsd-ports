--- src/freebsd.h.orig	2012-12-04 04:24:41.000000000 +0200
+++ src/freebsd.h	2012-12-04 04:24:52.000000000 +0200
@@ -10,6 +10,7 @@
 #include <fcntl.h>
 #include <kvm.h>
 #include <pthread.h>
+#include <stdbool.h>
 #if (defined(i386) || defined(__i386__))
 #include <machine/apm_bios.h>
 #endif /* i386 || __i386__ */
