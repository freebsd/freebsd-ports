--- src/clearlooks_style.c.orig	Sun Feb 27 01:45:14 2005
+++ src/clearlooks_style.c	Sun Feb 27 01:46:52 2005
@@ -487,14 +487,14 @@
 	
 	if (DETAIL ("tab"))
 	{
+		GdkColor tmp_color;
 		GdkRectangle new_area;
 	
 		cl_rectangle_set_button (&r, style, state_type, FALSE,
 								CL_CORNER_ROUND, CL_CORNER_ROUND,
 								CL_CORNER_ROUND, CL_CORNER_ROUND);
-
-		GdkColor tmp_color;
 		
+
 		if (state_type == GTK_STATE_ACTIVE)
 			shade (&style->bg[state_type], &tmp_color, 1.08);
 		else
@@ -754,6 +754,7 @@
 	if (widget && DETAIL ("button") && widget->parent &&
 	         (GTK_IS_TREE_VIEW(widget->parent) || GTK_IS_CLIST (widget->parent))) // headers
 	{
+		int nwidth;
 		gint columns = 0, column_index = 0;
 
 		if ( width < 2 || height < 2 )
@@ -762,7 +763,7 @@
 		if (GTK_IS_TREE_VIEW (widget->parent))
 			gtk_treeview_get_header_index (widget->parent, widget, &column_index, &columns);
 		
-		int nwidth = (column_index == columns-1) ? width : width+1;
+                nwidth = (column_index == columns-1) ? width : width+1;
 
 		cl_rectangle_set_button (&r, style, state_type, FALSE,
 		                        CL_CORNER_NONE, CL_CORNER_NONE,
@@ -1074,6 +1075,7 @@
 	}
 	else if (DETAIL ("menuitem"))
 	{
+		int corner;
 		gboolean menubar = (widget->parent && GTK_IS_MENU_BAR(widget->parent)) ? TRUE : FALSE;
 		gboolean flatmenu = FALSE;
 	
@@ -1081,7 +1083,7 @@
 		
 		shade (clearlooks_get_spot_color (CLEARLOOKS_RC_STYLE (style->rc_style)), &inner_lower, 1.3);
 
-		int corner = CL_CORNER_NARROW;
+		corner = CL_CORNER_NARROW;
 		
 		if (menubar)
 		{
