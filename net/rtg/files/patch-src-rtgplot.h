--- src/rtgplot.h	2003-09-24 15:43:39.000000000 +0100
+++ src/rtgplot.h.new	2010-04-20 21:41:37.131774833 +0100
@@ -11,6 +11,7 @@
 
 #include <gd.h>
 #include <gdfonts.h>
+#include <gdfontmb.h>
 #include <strings.h>
 
 #define XPLOT_AREA 500
@@ -95,6 +96,7 @@
     int scaley; 
     range_t range;
     image_t image;
+    char *titlestr;
 } graph_t;
 
 /* A linked list of colors that we iterate through each line */
@@ -106,6 +108,7 @@
 
 typedef struct arguments_struct {
     char *table[MAXTABLES];
+    char *tablename[MAXTABLES];
     int iid[MAXIIDS];
     int tables_to_plot;
     int iids_to_plot;
