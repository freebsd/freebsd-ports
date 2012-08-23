--- ./gtk/src/callbacks.c.orig	2012-08-23 21:44:53.000000000 +0800
+++ ./gtk/src/callbacks.c	2012-08-23 21:45:09.000000000 +0800
@@ -34,6 +34,7 @@
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
 
+#include <sys/socket.h>
 #include <netinet/in.h>
 #include <netdb.h>
 
