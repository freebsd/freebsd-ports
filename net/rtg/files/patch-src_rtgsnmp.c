--- src/rtgsnmp.c.orig	2003-09-25 18:23:35 UTC
+++ src/rtgsnmp.c
@@ -8,6 +8,11 @@
 #include "common.h"
 #include "rtg.h"
 
+config_t set;
+int lock;
+int waiting;
+hash_t hash;
+
 #ifdef OLD_UCD_SNMP
  #include "asn1.h"
  #include "snmp_api.h"
