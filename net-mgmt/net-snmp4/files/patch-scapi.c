--- ../../work/ucd-snmp-4.2.6/snmplib/scapi.c	2001-10-01 02:52:49.000000000 -0700
+++ snmplib/scapi.c	2008-03-04 16:41:52.000000000 -0800
@@ -56,6 +56,7 @@
 #include <openssl/hmac.h>
 #include <openssl/evp.h>
 #include <openssl/rand.h>
+#include <openssl/des.h>
 #endif
 
 #ifdef QUITFUN
