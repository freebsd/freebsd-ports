--- src/providers/data_provider_be.c.orig	2023-05-25 06:24:25 UTC
+++ src/providers/data_provider_be.c
@@ -25,6 +25,8 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <sys/un.h>
 #include <string.h>
 #include <sys/time.h>
