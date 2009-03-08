--- src/jingle-factory.c.orig	2009-03-08 13:03:05.000000000 -0400
+++ src/jingle-factory.c	2009-03-08 13:04:05.000000000 -0400
@@ -20,6 +20,10 @@
 
 #include "jingle-factory.h"
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
