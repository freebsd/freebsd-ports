--- src/libguppiplot/guppi-axis-markers.c.orig	2007-12-13 15:37:21.000000000 +0100
+++ src/libguppiplot/guppi-axis-markers.c	2007-12-13 15:38:10.000000000 +0100
@@ -47,10 +47,11 @@
 
 static guint gam_signals[LAST_SIGNAL] = { 0 };
 
+static void clear (GuppiAxisMarkers *);
+
 static void
 guppi_axis_markers_finalize (GtkObject * obj)
 {
-  static void clear (GuppiAxisMarkers *);
   GuppiAxisMarkers *gal = GUPPI_AXIS_MARKERS (obj);
 
   guppi_finalized (obj);
