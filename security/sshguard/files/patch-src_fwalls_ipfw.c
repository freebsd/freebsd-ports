--- src/fwalls/ipfw.c.orig	2015-05-05 01:58:28 UTC
+++ src/fwalls/ipfw.c
@@ -33,6 +33,7 @@
 #include "../config.h"
 #include "../sshguard_log.h"
 #include "../sshguard_fw.h"
+#include "parser/address.h"
 
 #define IPFWMOD_ADDRESS_BULK_REPRESENTATIVE     "FF:FF:FF:FF:FF:FF:FF:FF"
 
