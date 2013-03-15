--- ./src/tickr/tickr_socket.h.orig	2013-03-14 23:14:35.000000000 +0100
+++ ./src/tickr/tickr_socket.h	2013-03-14 23:15:07.000000000 +0100
@@ -51,6 +51,7 @@
 # include <winreg.h>
 # include <shlobj.h>
 #endif
+#include <netinet/in.h>
 #include "../libetm-0.4.4/libetm.h"
 
 #define CONNECT_TIMEOUT		5
