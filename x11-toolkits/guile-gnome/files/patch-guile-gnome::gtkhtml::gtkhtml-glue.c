
$FreeBSD$

--- guile-gnome/gtkhtml/gtkhtml-glue.c	2001/07/24 09:02:10	1.1
+++ guile-gnome/gtkhtml/gtkhtml-glue.c	2001/07/24 09:18:08
@@ -310,17 +310,20 @@
 static char s_gtk_html_set_iframe_parent[] = "gtk-html-set-iframe-parent";
 
 SCM
-sgtk_gtk_html_set_iframe_parent (SCM p_html, SCM p_parent)
+sgtk_gtk_html_set_iframe_parent (SCM p_html, SCM p_parent, SCM p_frame)
 {
   GtkHTML* c_html;
   GtkWidget* c_parent;
+  HTMLObject* c_frame;
   SCM_ASSERT (sgtk_is_a_gtkobj (gtk_html_get_type (), p_html), p_html, SCM_ARG1, s_gtk_html_set_iframe_parent);
   SCM_ASSERT (sgtk_is_a_gtkobj (gtk_widget_get_type (), p_parent), p_parent, SCM_ARG2, s_gtk_html_set_iframe_parent);
+  SCM_ASSERT (sgtk_is_a_gtkobj (html_object_get_type (), p_frame), p_frame, SCM_ARG3, s_gtk_html_set_iframe_parent);
 
   SCM_DEFER_INTS;
   c_html = (GtkHTML*)sgtk_get_gtkobj (p_html);
   c_parent = (GtkWidget*)sgtk_get_gtkobj (p_parent);
-  gtk_html_set_iframe_parent (c_html, c_parent);
+  c_frame = (HTMLObject*)sgtk_get_gtkobj (p_frame);
+  gtk_html_set_iframe_parent (c_html, c_parent, c_frame);
   SCM_ALLOW_INTS;
 
   return SCM_UNSPECIFIED;
