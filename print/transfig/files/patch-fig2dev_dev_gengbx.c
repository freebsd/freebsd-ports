--- fig2dev/dev/gengbx.c.orig	2020-08-25 12:18:01 UTC
+++ fig2dev/dev/gengbx.c
@@ -594,12 +594,6 @@ int define_aperture_for_arc(F_arc *a) {
 
 char   *cctype[] = { "none", "black", "white" };
 
-/* arrowhead arrays */
-Point   points[50];
-int     npoints;
-int     arrowx1, arrowy1;	/* first point of object */
-int     arrowx2, arrowy2;	/* second point of object */
-
 static F_point *p;
 
 /** Used to generate sequence numbers. */
