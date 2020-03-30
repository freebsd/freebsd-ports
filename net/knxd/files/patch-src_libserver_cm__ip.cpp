--- src/libserver/cm_ip.cpp.orig	2020-03-30 14:33:20 UTC
+++ src/libserver/cm_ip.cpp
@@ -21,6 +21,7 @@
 #include "config.h"
 
 #include <net/if.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <sys/socket.h>
 #include <unistd.h>
