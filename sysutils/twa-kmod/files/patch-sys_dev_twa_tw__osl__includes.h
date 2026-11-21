--- tw_osl_includes.h.orig
+++ tw_osl_includes.h
@@ -58,7 +58,12 @@
 
 #include <machine/bus.h>
 #include <machine/resource.h>
+#if __FreeBSD_version < 1403503 || \
+    (__FreeBSD_version >= 1500000 && __FreeBSD_version < 1500047)
 #include <machine/stdarg.h>
+#else
+#include <sys/stdarg.h>
+#endif
 
 #include <vm/vm.h>
 
