--- src/ufdbHostnames.c.orig	2016-10-21 06:25:59 UTC
+++ src/ufdbHostnames.c
@@ -17,6 +17,7 @@
 #include "ufdbHashtable.h"
 
 #include <time.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <netdb.h>
 #include <arpa/inet.h>
