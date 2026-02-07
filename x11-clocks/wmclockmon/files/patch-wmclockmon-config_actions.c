--- wmclockmon-config/actions.c.orig	2005-04-07 09:37:43 UTC
+++ wmclockmon-config/actions.c
@@ -19,6 +19,24 @@
 #include "edit.h"
 #include "actions.h"
 
+GtkWidget *application;
+GtkWidget *alarmlist;
+GtkWidget *wid_backlight;
+GtkWidget *wid_blink;
+GtkWidget *wid_styledir;
+GtkWidget *wid_stylename;
+GtkWidget *wid_color;
+GtkWidget *wid_command;
+GtkWidget *wid_msgcmd;
+GtkWidget *wid_h12;
+GtkWidget *wid_clk;
+GtkWidget *wid_itm;
+GtkWidget *wid_bin;
+GtkWidget *wid_locale;
+GtkWidget *wid_showcal;
+GtkWidget *wid_calalrms;
+
+int selected_row;
 
 void quit_app() {
     FREE(command);
