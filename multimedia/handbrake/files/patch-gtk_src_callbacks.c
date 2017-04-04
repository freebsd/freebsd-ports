--- gtk/src/callbacks.c.orig	2017-02-25 20:56:19 UTC
+++ gtk/src/callbacks.c
@@ -46,6 +46,9 @@
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
 
+#if defined( __FreeBSD__ )
+#include <sys/socket.h>
+#endif
 #include <netinet/in.h>
 #include <netdb.h>
 
@@ -5537,4 +5540,3 @@ void ghb_container_empty(GtkContainer *c
 {
     gtk_container_foreach(c, container_empty_cb, NULL);
 }
-
