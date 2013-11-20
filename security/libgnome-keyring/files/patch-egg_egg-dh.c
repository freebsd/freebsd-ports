--- egg/egg-dh.c.orig	Wed Aug  8 21:00:54 2012
+++ egg/egg-dh.c	Sat Oct 27 14:36:16 2012
@@ -27,6 +27,8 @@
 /* Enabling this is a complete security compromise */
 #define DEBUG_DH_SECRET 0
 
+EGG_SECURE_DECLARE (dh);
+
 typedef struct _DHGroup {
 	const gchar *name;
 	guint bits;
