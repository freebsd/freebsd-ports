--- network-utilities/gnome-remote-shell.c.orig	Mon Sep  1 01:56:21 2003
+++ network-utilities/gnome-remote-shell.c	Mon Sep  1 01:58:11 2003
@@ -23,6 +23,9 @@
 #endif
 
 #include <netdb.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <gconf/gconf-client.h>
 #include <gtk/gtkdialog.h>
 #include <gtk/gtkentry.h>
