--- src/keyserver.c.orig	Wed Jan 15 16:52:09 2003
+++ src/keyserver.c	Wed Jan 15 16:52:34 2003
@@ -24,6 +24,7 @@
 #endif
 #include <stdio.h>
 #ifdef HAVE_NETDB_H
+# include <sys/types.h>
 # include <sys/socket.h>
 # include <netinet/in.h>
 # include <arpa/inet.h>
