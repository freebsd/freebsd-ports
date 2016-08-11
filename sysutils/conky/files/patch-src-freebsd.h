--- src/freebsd.h.orig	2012-05-03 21:08:27 UTC
+++ src/freebsd.h
@@ -10,6 +10,7 @@
 #include <fcntl.h>
 #include <kvm.h>
 #include <pthread.h>
+#include <stdbool.h>
 #if (defined(i386) || defined(__i386__))
 #include <machine/apm_bios.h>
 #endif /* i386 || __i386__ */
