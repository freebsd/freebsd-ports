--- src/plgridd.c.orig	2019-06-01 23:24:33 UTC
+++ src/plgridd.c
@@ -33,7 +33,7 @@
 // PLPLOT_NONN not #defined or tested for more than a decade.
 #ifdef PLPLOT_NONN // another DTLI, based only on QHULL, not nn
 #ifdef HAS_LIBQHULL_INCLUDE
-#include <libqhull/qhull_a.h>
+#include <libqhull_r/qhull_ra.h>
 #else //#ifdef HAS_LIBQHULL_INCLUDE
 #include <qhull/qhull_a.h>
 #endif //#ifdef HAS_LIBQHULL_INCLUDE
