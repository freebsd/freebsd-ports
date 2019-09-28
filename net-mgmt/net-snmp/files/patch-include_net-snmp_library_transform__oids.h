--- include/net-snmp/library/transform_oids.h.orig	2018-07-16 14:33:40 UTC
+++ include/net-snmp/library/transform_oids.h
@@ -48,6 +48,8 @@ NETSNMP_IMPORT oid      usmDESPrivProtocol[10];
 
 NETSNMP_IMPORT oid      usmAESPrivProtocol[10];
 NETSNMP_IMPORT oid      *usmAES128PrivProtocol; /* backwards compat */
+NETSNMP_IMPORT oid      *usmAES192PrivProtocol; /* backwards compat */
+NETSNMP_IMPORT oid      *usmAES256PrivProtocol; /* backwards compat */
 
 /*
  * backwards compatibility. should not be used in internal code.
