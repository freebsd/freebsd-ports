--- include/net-snmp/library/transform_oids.h.orig	Wed Dec  8 19:34:06 2004
+++ include/net-snmp/library/transform_oids.h	Wed Dec  8 19:34:34 2004
@@ -23,6 +23,8 @@
 /* XXX: OIDs not defined yet */
 extern oid      usmAESPrivProtocol[10]; /* == { 1,3,6,1,6,3,10,1,2,4 }; */
 extern oid      *usmAES128PrivProtocol; /* backwards compat */
+extern oid      *usmAES192PrivProtocol; /* backwards compat */
+extern oid      *usmAES256PrivProtocol; /* backwards compat */
 
 #define USM_AUTH_PROTO_NOAUTH_LEN 10
 #define USM_AUTH_PROTO_MD5_LEN 10
