--- engines/clearlooks/src/clearlooks_style.c-	Sat Mar 11 21:14:40 2006
+++ engines/clearlooks/src/clearlooks_style.c	Thu Mar 16 11:29:07 2006
@@ -980,14 +980,17 @@
 			    *shadow = clearlooks_style->shade_gc[4];
 		GdkColor upper_color = *clearlooks_get_spot_color (CLEARLOOKS_RC_STYLE (style->rc_style)),
 				 lower_color;
-		
+		GtkAdjustment *adjustment;
+		GtkOrientation orientation;
+		gint fill_size;
+
 		gtk_widget_style_get (widget, "slider-length", &slider_length, NULL);
 		
-		GtkAdjustment *adjustment = gtk_range_get_adjustment (GTK_RANGE (widget));
+		adjustment = gtk_range_get_adjustment (GTK_RANGE (widget));
 		
-		GtkOrientation orientation = GTK_RANGE (widget)->orientation;
+		orientation = GTK_RANGE (widget)->orientation;
 		
-		gint fill_size = ((orientation ? height : width) - slider_length) * 
+		fill_size = ((orientation ? height : width) - slider_length) * 
 		                 (1 / ((adjustment->upper - adjustment->lower) / 
 		                      (adjustment->value - adjustment->lower)))
 		                 + slider_length / 2;
