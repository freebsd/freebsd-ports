--- gtk/gtkdatabox_ruler.c.orig	2011-07-16 04:25:04.000000000 +0900
+++ gtk/gtkdatabox_ruler.c	2012-06-02 13:36:15.000000000 +0900
@@ -32,6 +32,11 @@
 #include <math.h>
 #include <glib/gprintf.h>
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x) (log(x) / log(2))
+#endif
+
 #define RULER_SIZE          14
 
 #define ROUND(x) ((int) ((x) + 0.5))
