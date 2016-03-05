--- src/download.c.orig	2015-11-28 14:58:25 UTC
+++ src/download.c
@@ -36,6 +36,9 @@
 #include <System.h>
 #ifdef WITH_WEBKIT
 # include <netdb.h>
+# include <sys/types.h>
+# include <sys/socket.h>
+# include <netinet/in.h>
 # include <arpa/inet.h>
 # include <webkit/webkit.h>
 #else
