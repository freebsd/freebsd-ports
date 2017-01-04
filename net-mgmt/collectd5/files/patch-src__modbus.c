--- src/modbus.c.orig	2016-12-12 03:03:36.712279086 -0500
+++ src/modbus.c	2017-01-03 08:12:39.318883000 -0500
@@ -26,6 +26,9 @@
 #include "configfile.h"
 #include "plugin.h"
 
+/* FreeBSD needs this */
+#include <sys/socket.h> 
+
 #include <modbus.h>
 #include <netdb.h>
 #include <sys/socket.h>
