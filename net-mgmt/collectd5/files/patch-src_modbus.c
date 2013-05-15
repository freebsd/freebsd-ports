--- src/modbus.c.orig       2013-01-27 17:47:18.246255000 +0400
+++ src/modbus.c    2013-05-14 18:40:05.000000000 +0400
@@ -25,6 +25,9 @@
 #include "plugin.h"
 #include "configfile.h"
 
+/* FreeBSD needs this */
+#include <sys/socket.h> 
+
 #include <netdb.h>
 
 #include <modbus/modbus.h>
