--- library/gnome-keyring.c.orig	2008-02-26 22:05:10.000000000 -0600
+++ library/gnome-keyring.c	2008-02-26 22:05:30.000000000 -0600
@@ -50,6 +50,8 @@
 #include <dbus/dbus.h>
 #endif
 
+extern char **environ;
+
 typedef enum {
 	CALLBACK_DONE,
 	CALLBACK_GET_STRING,
