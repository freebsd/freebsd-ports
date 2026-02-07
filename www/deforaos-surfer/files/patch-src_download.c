--- src/download.c.orig	2022-11-15 01:17:05 UTC
+++ src/download.c
@@ -39,6 +39,9 @@
 # include <sys/types.h>
 # include <sys/socket.h>
 # include <netdb.h>
+# include <sys/types.h>
+# include <sys/socket.h>
+# include <netinet/in.h>
 # include <arpa/inet.h>
 # include <webkit/webkit.h>
 #elif defined(WITH_WEBKIT2)
