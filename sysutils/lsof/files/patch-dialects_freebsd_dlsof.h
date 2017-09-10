--- dialects/freebsd/dlsof.h.orig	2017-09-10 14:02:39 UTC
+++ dialects/freebsd/dlsof.h
@@ -486,6 +486,13 @@ struct vop_advlock_args { int dummy; };	/* to pacify l
 #  endif	/* FREEBSDV<5000 */
 # endif        /* FREEBSDV>=2020 */
 
+/*
+ * Inclusion of kernel headers with _KERNEL specified causes a conflict with
+ * userspace. bzero is a macro, but is redefined to be a function in string.h
+ * Work around by just undefing.
+ */
+#undef bzero
+
 #include <string.h>
 
 
