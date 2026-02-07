--- src/out-tcp-services.c.orig	2022-08-02 04:53:49 UTC
+++ src/out-tcp-services.c
@@ -1,6 +1,7 @@
 #include "out-tcp-services.h"
 #include <string.h>
 #include <stdlib.h>
+#include <arpa/inet.h>
 
 #ifndef WIN32
 #include <netdb.h>
