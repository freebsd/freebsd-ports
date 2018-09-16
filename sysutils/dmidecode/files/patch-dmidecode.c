--- dmidecode.c.orig	2018-09-14 13:52:12 UTC
+++ dmidecode.c
@@ -66,6 +66,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <arpa/inet.h>
+#include <sys/socket.h>
 
 #ifdef __FreeBSD__
 #include <errno.h>
