--- wmclockmon-cal/mainwindow.h.orig	2005-04-07 09:37:43 UTC
+++ wmclockmon-cal/mainwindow.h
@@ -7,20 +7,20 @@
 
 #include <gtk/gtk.h>
 
-GtkWidget *application;
-GtkWidget *alarmlist;
-GtkWidget *wid_backlight;
-GtkWidget *wid_blink;
-GtkWidget *wid_styledir;
-GtkWidget *wid_stylename;
-GtkWidget *wid_color;
-GtkWidget *wid_command;
-GtkWidget *wid_msgcmd;
-GtkWidget *wid_h12;
-GtkWidget *wid_itm;
-GtkWidget *wid_locale;
+extern GtkWidget *application;
+extern GtkWidget *alarmlist;
+extern GtkWidget *wid_backlight;
+extern GtkWidget *wid_blink;
+extern GtkWidget *wid_styledir;
+extern GtkWidget *wid_stylename;
+extern GtkWidget *wid_color;
+extern GtkWidget *wid_command;
+extern GtkWidget *wid_msgcmd;
+extern GtkWidget *wid_h12;
+extern GtkWidget *wid_itm;
+extern GtkWidget *wid_locale;
 
-int selected_row;
+extern int selected_row;
 
 gint list_unsel_cb (GtkCList *clist,
         gint row,
