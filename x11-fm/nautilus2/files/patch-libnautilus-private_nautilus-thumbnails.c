--- libnautilus-private/nautilus-thumbnails.c.orig	Tue Jul  9 19:09:29 2002
+++ libnautilus-private/nautilus-thumbnails.c	Tue Jul  9 19:09:19 2002
@@ -309,6 +309,7 @@
 	pthread_attr_init (&thread_attributes);
 	pthread_attr_setdetachstate (&thread_attributes,
 				     PTHREAD_CREATE_DETACHED);
+	pthread_attr_setstacksize (&thread_attributes, 128*1024);
 #ifdef DEBUG_THUMBNAILS
 	g_message ("(Main Thread) Creating thumbnails thread\n");
 #endif
