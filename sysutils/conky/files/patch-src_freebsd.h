--- src/freebsd.h.orig	2019-01-08 01:26:24 UTC
+++ src/freebsd.h
@@ -41,6 +41,8 @@
 #include <machine/apm_bios.h>
 #endif /* i386 || __i386__ */
 
+extern kvm_t *kd;
+
 int get_entropy_avail(unsigned int *);
 int get_entropy_poolsize(unsigned int *);
 void print_sysctlbyname(struct text_object *, char *, unsigned int);
