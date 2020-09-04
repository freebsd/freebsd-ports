--- relayd/parse.y.orig	2014-08-10 20:08:47 UTC
+++ relayd/parse.y
@@ -55,6 +55,8 @@
 
 #include <openssl/ssl.h>
 
+#define IN_MAIN
+  
 #include "relayd.h"
 #include "http.h"
 // FreeBSD #include "snmp.h"
