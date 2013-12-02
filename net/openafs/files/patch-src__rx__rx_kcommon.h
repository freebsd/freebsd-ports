diff --git a/src/rx/rx_kcommon.h b/src/rx/rx_kcommon.h
index 64d03cb..58bf69c 100644
--- a/src/rx/rx_kcommon.h
+++ b/src/rx/rx_kcommon.h
@@ -141,7 +141,11 @@ typedef unsigned short etap_event_t;
 #include "h/errno.h"
 #if !(defined(AFS_SUN5_ENV) && defined(KERNEL))
 /* if sys/systm.h includes varargs.h some versions of solaris have conflicts */
-#include "stdarg.h"
+# if defined(AFS_FBSD_ENV)
+#  include "machine/stdarg.h"
+# else
+#  include "stdarg.h"
+# endif
 #endif
 #ifdef KERNEL
 #include "afs/sysincludes.h"
