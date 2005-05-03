--- libbalsa/imap/imap-handle.c.orig	Sun May  1 17:37:58 2005
+++ libbalsa/imap/imap-handle.c	Tue May  3 01:39:13 2005
@@ -23,6 +23,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <glib.h>
 #include <glib-object.h>
