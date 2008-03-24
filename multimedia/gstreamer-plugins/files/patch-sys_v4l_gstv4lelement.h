--- sys/v4l/gstv4lelement.h.orig	2008-02-23 15:31:39.000000000 -0500
+++ sys/v4l/gstv4lelement.h	2008-02-23 15:32:00.000000000 -0500
@@ -91,6 +91,8 @@ struct _GstV4lElement {
   /* X-overlay */
   GstV4lXv *xv;
   gulong xwindow_id;
+
+  gboolean use_read;
 };
 
 struct _GstV4lElementClass {
