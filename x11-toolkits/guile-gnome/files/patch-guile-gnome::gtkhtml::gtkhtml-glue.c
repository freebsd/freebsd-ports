--- guile-gnome/gtkhtml/gtkhtml-glue.c.orig	Mon Feb  5 22:46:22 2001
+++ guile-gnome/gtkhtml/gtkhtml-glue.c	Mon Nov 11 22:52:04 2002
@@ -110,7 +110,7 @@
 extern sgtk_boxed_info sgtk_gtimer_info;
 
 GtkTypeInfo sgtk_gtk_htmlstream_info_gtk = {
-  "GtkHTMLStream", "sizeof (GtkHTMLStream)", 0,
+  "GtkHTMLStream", 0, 0,
   (GtkClassInitFunc) NULL,
   (GtkObjectInitFunc) NULL,
   (GtkArgSetFunc) NULL,
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
@@ -399,21 +402,23 @@
 static char s_gtk_html_request_paste[] = "gtk-html-request-paste";
 
 SCM
-sgtk_gtk_html_request_paste (SCM p_html, SCM p_type, SCM p_time)
+sgtk_gtk_html_request_paste (SCM p_html, SCM p_selection, SCM p_type, SCM p_time)
 {
   gint cr_ret;
   GtkHTML* c_html;
+  GdkAtom c_selection;
   gint c_type;
   gint c_time;
   SCM_ASSERT (sgtk_is_a_gtkobj (gtk_html_get_type (), p_html), p_html, SCM_ARG1, s_gtk_html_request_paste);
-  c_type = scm_num2long (p_type, (char *)SCM_ARG2, s_gtk_html_request_paste);
-  c_time = scm_num2long (p_time, (char *)SCM_ARG3, s_gtk_html_request_paste);
+  c_selection = scm_num2long (p_selection, (char *)SCM_ARG2, s_gtk_html_request_paste);
+  c_type = scm_num2long (p_type, (char *)SCM_ARG3, s_gtk_html_request_paste);
+  c_time = scm_num2long (p_time, (char *)SCM_ARG4, s_gtk_html_request_paste);
 
   SCM_DEFER_INTS;
   c_html = (GtkHTML*)sgtk_get_gtkobj (p_html);
   ;
   ;
-  cr_ret = gtk_html_request_paste (c_html, c_type, c_time);
+  cr_ret = gtk_html_request_paste (c_html, c_selection, c_type, c_time, 0);
   SCM_ALLOW_INTS;
 
   return scm_long2num (cr_ret);
@@ -693,7 +698,7 @@
 
   SCM_DEFER_INTS;
   c_html = (GtkHTML*)sgtk_get_gtkobj (p_html);
-  gtk_html_paste (c_html);
+  gtk_html_paste (c_html, 0);
   SCM_ALLOW_INTS;
 
   return SCM_UNSPECIFIED;
