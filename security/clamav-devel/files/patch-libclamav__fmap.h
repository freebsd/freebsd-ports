--- ./libclamav/fmap.h.orig	2009-12-21 11:10:50.000000000 -0200
+++ ./libclamav/fmap.h	2009-12-21 11:11:00.000000000 -0200
@@ -21,6 +21,15 @@
 #ifndef __FMAP_H
 #define __FMAP_H
 
+#if defined(__FreeBSD__)
+/* Needed to check FreeBSD version */
+#include <osreldate.h>
+
+#if (__FreeBSD_version < 800000)
+#include <unistd.h>
+#endif
+#endif
+
 #include <time.h>
 #include "cltypes.h"
 
