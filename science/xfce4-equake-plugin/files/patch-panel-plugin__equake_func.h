Fix errors with clang 3.3

--- panel-plugin/equake_func.h.orig	2013-07-31 23:42:02.000000000 +0000
+++ panel-plugin/equake_func.h	2013-08-02 18:49:06.000000000 +0000
@@ -26,23 +26,23 @@
 (
   GtkWidget *event_box,
   GdkEventButton *event,
-  gpointer data;
+  gpointer data
 );
 
 void equake_setprefs
 (
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 void equake_getprefs
 (
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 void equake_saveprefs
 (
   struct Equake_Data *equakedata,
-  FILE *fp;
+  FILE *fp
 );
 
 /*static void equake_applet_change_background
@@ -50,7 +50,7 @@
   XfcePanelPlugin *applet,
   XfcePanelPluginBackgroundType type,
   GdkColor  *colour,
-  GdkPixmap *pixmap;
+  GdkPixmap *pixmap
 );*/
 
 static void equake_applet_fill
@@ -60,7 +60,7 @@
 
 void setdefaults
 (
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 /* process the arguments given at program startup, if any */
@@ -68,52 +68,52 @@
 (
   int arg,
   char **argv,
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 int processdata_daily
 (
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 int render_equake_label
 (
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 static void set_label_tooltip_text
 (
-  GtkWidget *label,
+  GtkLabel *label,
   char *lbltxt,
-  char *tooltiptxt;
+  char *tooltiptxt
 );
 
 int processdata
 (
   struct Equake_Data *equakedata,
-  int period;
+  int period
 );
 
 void set_signature_file
 (
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 void alert_heavy_quake
 (
   struct Equake_Data *equakedata,
-  int pos;
+  int pos
 );
 
 void set_magnitude_icon
 (
   struct Equake_Data *equakedata,
-  int pos;
+  int pos
 );
 
 int convert_localtime
 (
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 long long diff_tm
@@ -124,14 +124,14 @@
 
 int eventloop
 (
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 /* print error message and exit */
 void error
 (
   char *msg,
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 /* In case of partial send make sure everything is sent or give an error */
@@ -139,7 +139,7 @@
 (
   int socket, 
   char *buf, 
-  int *len;
+  int *len
 );
 
 int receiveall
@@ -147,7 +147,7 @@
   int socket,
   char *buf,
   int len,
-  int period;
+  int period
 );
 
 /*
@@ -157,7 +157,7 @@
 int getquakedata
 (
   struct Equake_Data *equakedata,
-  int period;
+  int period
 );
 
 int startequake
@@ -165,38 +165,38 @@
   XfcePanelPlugin *applet,
   GtkWidget *label,
   GtkWidget *logo,
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 /* menu functions */
 static void do_update
 (
   XfcePanelPlugin *applet, 
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 static void load_details
 (
   XfcePanelPlugin *applet,
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 static void load_map
 (
   XfcePanelPlugin *applet,
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 static void load_didyoufeelit
 (
   XfcePanelPlugin *applet,
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 static void display_properties_dialog 
 (
   XfcePanelPlugin *applet,
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 static void set_properties_from_dialog
@@ -205,41 +205,42 @@
   int willalert,
   int alertheavy,
   int sigfilemag,
-  int monitormag;
+  int monitormag,
+  struct Equake_Data *equakedata
 );
 
 static void display_about_dialog
 (
   XfcePanelPlugin *applet,
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 static void display_dialog
 (
-  char *t;
+  char *t
 );
 
 static void display_url
 (
-  char *url;
+  char *url
 );
 
 static void display_nonmodaldialog
 (
   GtkWidget *dialog,
-  char *t;
+  char *t
 );
 
 static void display_lastday
 (
   XfcePanelPlugin *applet,
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 static void display_lasthour
 (
   XfcePanelPlugin *applet,
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 static void fill_text_period
@@ -247,31 +248,31 @@
   struct Equake_Data *equakedata,
   char *running,
   char *periodtext,
-  int period;
+  int period
 );
 
 static void display_period_window
 (
   char *text,
-  int period;
+  int period
 );
 
 static void display_lastperiod
 (
-  struct Equake_Data *equakedata;
-  int period;
+  struct Equake_Data *equakedata,
+  int period
 );
 
 static void equake_orientation_changedi
 (
   XfcePanelPlugin *applet,
   GtkOrientation orientation,
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
 
 static void equake_size_changed
 (
   XfcePanelPlugin *applet,
   int size,
-  struct Equake_Data *equakedata;
+  struct Equake_Data *equakedata
 );
