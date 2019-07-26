--- dialects/freebsd/dlsof.h.orig	2019-05-08 07:32:25 UTC
+++ dialects/freebsd/dlsof.h
@@ -45,6 +45,12 @@
 #include <signal.h>
 #include <unistd.h>
 
+#if    FREEBSDV>=13000
+/* This header is a huge mess.  Please don't support EOL FreeBSD releases. */
+#define        _KERNEL 1
+#include <sys/_lock.h>
+#undef _KERNEL
+#endif         /* FREEBSDV>=13000 */
 # if	FREEBSDV>=4000
 #  if	FREEBSDV>=5000
 #   if	FREEBSDV<6020
@@ -104,6 +110,12 @@ typedef	struct device	*device_t;
 
 
 #include <sys/conf.h>
+
+/* 
+ * include <stdbool.h> for refcount(9)
+ */
+#include <stdbool.h>
+ 
 
 #  if	defined(HAS_VM_MEMATTR_T)
 #undef	vm_memattr_t
