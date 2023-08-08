--- wmclockmon-cal/main.c.orig	2022-12-03 21:39:45 UTC
+++ wmclockmon-cal/main.c
@@ -15,6 +15,22 @@
 #include "mainwindow.h"
 #include "main.h"
 
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
+GtkWidget *wid_itm;
+GtkWidget *wid_locale;
+
+int selected_row;
+
+struct tm *timeinfos;
 
 void Usage () {
     printf("Usage: "PACKAGE"-cal [-h] [-v]\n"
