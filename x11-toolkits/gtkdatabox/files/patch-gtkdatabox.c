--- gtk/gtkdatabox.c.orig	2011-07-16 04:24:33.000000000 +0900
+++ gtk/gtkdatabox.c	2012-06-02 13:32:51.000000000 +0900
@@ -26,6 +26,11 @@
 #include <gtk/gtkgc.h>
 #include <math.h>
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x) (log(x) / log(2))
+#endif
+
 
 static gint gtk_databox_button_press (GtkWidget * widget,
 				      GdkEventButton * event);
