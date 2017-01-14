--- dialects/freebsd/dlsof.h.orig	2016-09-22 20:02:53 UTC
+++ dialects/freebsd/dlsof.h
@@ -87,6 +87,7 @@
 #define	boolean_t	int
 #  endif	/* defined(NEEDS_BOOLEAN_T) */
 
+#define KLD_MODULE
 #include <sys/conf.h>
 
 #  if	defined(HAS_VM_MEMATTR_T)
