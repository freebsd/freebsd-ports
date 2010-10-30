--- src/freebsd.h.orig	2010-10-24 03:14:11.000000000 +0300
+++ src/freebsd.h	2010-10-24 03:13:05.000000000 +0300
@@ -9,11 +9,13 @@
 #include <sys/ucred.h>
 #include <fcntl.h>
 #include <kvm.h>
+#include <pthread.h>
 #if (defined(i386) || defined(__i386__))
 #include <machine/apm_bios.h>
 #endif /* i386 || __i386__ */
 
 kvm_t *kd;
+pthread_mutex_t kvm_proc_mutex;
 
 int get_entropy_avail(unsigned int *);
 int get_entropy_poolsize(unsigned int *);
