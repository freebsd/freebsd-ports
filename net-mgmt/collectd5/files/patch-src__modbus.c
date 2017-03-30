--- src/modbus.c.orig	2017-01-23 07:53:57 UTC
+++ src/modbus.c
@@ -26,6 +26,9 @@
 #include "configfile.h"
 #include "plugin.h"
 
+/* FreeBSD needs this */
+#include <sys/socket.h> 
+
 #include <modbus.h>
 #include <netdb.h>
 #include <sys/socket.h>
