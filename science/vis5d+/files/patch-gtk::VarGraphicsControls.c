--- gtk/VarGraphicsControls.c.orig	Fri Aug 20 19:35:10 2004
+++ gtk/VarGraphicsControls.c	Fri Aug 20 19:35:46 2004
@@ -38,7 +38,7 @@
 static gint last_level;
 void hs_label(v5d_var_info *vinfo);
 void chs_label(v5d_var_info *vinfo);
-
+void update_vslice_controls(v5d_var_info *vinfo, gint type);
 
 gboolean
 on_interval_hscale_button_changed      (GtkWidget       *widget,
