--- gtk/gtkdatabox.c.orig	2018-11-02 17:08:28 UTC
+++ gtk/gtkdatabox.c
@@ -23,6 +23,11 @@
 #include <gtk/gtk.h>
 #include <math.h>
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x) (log(x) / log(2))
+#endif
+
 
 static gint gtk_databox_button_press (GtkWidget * widget,
                                       GdkEventButton * event);
