--- src/udpproto.c.orig	2018-08-30 18:56:26 UTC
+++ src/udpproto.c
@@ -4,7 +4,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <unistd.h>
-
+#include <limits.h>
 #include <arpa/inet.h>
 
 #include "udpproto.h"
