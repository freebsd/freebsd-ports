--- Intel/cachesize.c.orig	Tue Dec 18 13:43:49 2001
+++ Intel/cachesize.c	Tue Dec 18 13:45:27 2001
@@ -2,6 +2,15 @@
  * $Id: cachesize.c,v 1.2 2001/12/10 21:48:37 davej Exp $
  */
 
+#ifdef __FreeBSD__
+#  if __FreeBSD__==5
+#    include <stdint.h>
+#  else
+#    include <inttypes.h>
+#    include <sys/types.h>
+#  endif
+#endif
+
 #include "../x86info.h"
 
 void get_intel_cacheinfo (struct cpudata *c)
