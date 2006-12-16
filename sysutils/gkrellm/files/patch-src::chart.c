Index: src/chart.c
diff -u -p src/chart.c.orig src/chart.c
--- src/chart.c.orig	Sun Mar 17 10:44:49 2002
+++ src/chart.c	Sun Dec 17 00:10:41 2006
@@ -22,6 +22,8 @@
 #include "gkrellm.h"
 #include "gkrellm_private_proto.h"
 
+static void	set_grid_resolution_spin_button(Chart *, gint);
+
   /* For grid images of height 2 pixels, make room at bottom of chartdata
   |  window so both pixel lines will show.
   */
@@ -470,7 +472,6 @@ draw_chartdata_lines(Chart *cp, ChartDat
 static void
 set_auto_grid_resolution(Chart *cp, gint maxval)
 	{
-	static void	set_grid_resolution_spin_button(Chart *, gint);
 	ChartConfig	*cf = cp->config;
 	gint		grids, grid_res, maxval_base;
 
