--- src/rtgplot.h.orig	2003-09-24 14:43:39 UTC
+++ src/rtgplot.h
@@ -11,6 +11,7 @@
 
 #include <gd.h>
 #include <gdfonts.h>
+#include <gdfontmb.h>
 #include <strings.h>
 
 #define XPLOT_AREA 500
@@ -95,6 +96,7 @@ typedef struct graph_struct {
     int scaley; 
     range_t range;
     image_t image;
+    char *titlestr;
 } graph_t;
 
 /* A linked list of colors that we iterate through each line */
@@ -106,6 +108,7 @@ typedef struct color_struct {
 
 typedef struct arguments_struct {
     char *table[MAXTABLES];
+    char *tablename[MAXTABLES];
     int iid[MAXIIDS];
     int tables_to_plot;
     int iids_to_plot;
