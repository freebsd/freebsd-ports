--- gtk/gtkdatabox_ruler.c.orig	2018-06-29 20:20:11 UTC
+++ gtk/gtkdatabox_ruler.c
@@ -34,6 +34,11 @@
 
 #include <string.h>
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x) (log(x) / log(2))
+#endif
+
 #define RULER_SIZE          14
 
 #define ROUND(x) ((int) ((x) + 0.5))
