--- src/modbus.c.orig	2016-09-11 08:10:25 UTC
+++ src/modbus.c
@@ -25,6 +25,9 @@
 #include "common.h"
 #include "plugin.h"
 
+/* FreeBSD needs this */
+#include <sys/socket.h> 
+
 #include <netdb.h>
 
 #include <modbus.h>
