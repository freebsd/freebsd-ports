--- libempathy/empathy-tp-file.c.orig	2009-06-15 18:52:39.000000000 +0200
+++ libempathy/empathy-tp-file.c	2009-06-15 18:53:45.000000000 +0200
@@ -29,6 +29,7 @@
 #include <arpa/inet.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <sys/un.h>
 
 #include <glib/gi18n-lib.h>
