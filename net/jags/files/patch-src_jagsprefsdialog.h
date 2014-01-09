--- ./src/jagsprefsdialog.h.orig	2003-09-04 23:14:54.000000000 +0200
+++ ./src/jagsprefsdialog.h	2014-01-08 10:20:11.000000000 +0100
@@ -57,4 +57,10 @@
   ~JagsPrefsDialog();
 };
 
+gint onPluginsChanged(GtkWidget *, GdkEvent *, JagsPrefsDialog *pd);
+gint on_cancel(GtkWidget *widget, JagsConfig *conf);
+gint on_apply(GtkWidget *widget, JagsConfig *conf2);
+gint on_close(GtkWidget *widget, JagsConfig *conf);
+void on_toggle_sound(GtkWidget *widget, JagsConfig *conf);
+
 #endif
