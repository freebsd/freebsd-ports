--- gal/widgets/e-canvas.c.orig	Tue May 24 01:16:33 2005
+++ gal/widgets/e-canvas.c	Tue May 24 01:16:51 2005
@@ -1015,7 +1015,7 @@ void e_canvas_popup_tooltip (ECanvas *ca
 
 void e_canvas_hide_tooltip  (ECanvas *canvas)
 {
-	if (canvas->tooltip_window) {
+	if (canvas && canvas->tooltip_window) {
 		gtk_widget_destroy (canvas->tooltip_window);
 		canvas->tooltip_window = NULL;
 	}
