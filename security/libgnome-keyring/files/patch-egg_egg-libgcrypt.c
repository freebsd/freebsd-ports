--- egg/egg-libgcrypt.c.orig	Wed Aug  8 21:00:54 2012
+++ egg/egg-libgcrypt.c	Sat Oct 27 14:36:16 2012
@@ -28,6 +28,8 @@
 
 #include <gcrypt.h>
 
+EGG_SECURE_DECLARE (libgcrypt);
+
 static void
 log_handler (gpointer unused, int unknown, const gchar *msg, va_list va)
 {
