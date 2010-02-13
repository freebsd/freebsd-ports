--- agent/auto_nlist.c.orig	Thu Feb  7 20:42:03 2002
+++ agent/auto_nlist.c	Sun Nov 17 00:40:52 2002
@@ -31,6 +31,15 @@
 #endif
 #endif
 
+#if HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+
+#if defined(__FreeBSD__) && (__FreeBSD_version >= 500000)
+#include <sys/types.h>
+#include <sys/time.h>
+#endif
+
 #include "auto_nlist.h"
 #include "autonlist.h"
 #include "kernel.h"
