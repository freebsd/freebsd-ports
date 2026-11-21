--- tw_osl_share.h.orig
+++ tw_osl_share.h
@@ -55,7 +55,12 @@
 
 #include <machine/bus.h>
 #include <machine/endian.h>
+#if __FreeBSD_version < 1403503 || \
+    (__FreeBSD_version >= 1500000 && __FreeBSD_version < 1500047)
 #include <machine/stdarg.h>
+#else
+#include <sys/stdarg.h>
+#endif
 
 #include <dev/pci/pcivar.h>
 
