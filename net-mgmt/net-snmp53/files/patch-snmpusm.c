--- snmplib/snmpusm.c.orig	Wed Dec  8 19:32:52 2004
+++ snmplib/snmpusm.c	Wed Dec  8 19:33:30 2004
@@ -89,6 +89,8 @@
 oid             usmAESPrivProtocol[10] = { 1, 3, 6, 1, 6, 3, 10, 1, 2, 4 };
 /* backwards compat */
 oid             *usmAES128PrivProtocol = usmAESPrivProtocol;
+oid             *usmAES192PrivProtocol = usmAESPrivProtocol;
+oid             *usmAES256PrivProtocol = usmAESPrivProtocol;
 
 static u_int    dummy_etime, dummy_eboot;       /* For ISENGINEKNOWN(). */
 
