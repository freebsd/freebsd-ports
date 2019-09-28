--- snmplib/snmpusm.c.orig	2018-07-16 14:33:40 UTC
+++ snmplib/snmpusm.c
@@ -117,6 +117,8 @@ oid             usmDESPrivProtocol[10] = { 1, 3, 6, 1,
 oid    usmAESPrivProtocol[10] = { 1, 3, 6, 1, 6, 3, 10, 1, 2, 4 };
 /* backwards compat */
 oid    *usmAES128PrivProtocol = usmAESPrivProtocol;
+oid    *usmAES192PrivProtocol = usmAESPrivProtocol;
+oid    *usmAES256PrivProtocol = usmAESPrivProtocol;
 
 #ifdef NETSNMP_DRAFT_BLUMENTHAL_AES_04
     /* OIDs from http://www.snmp.com/eso/esoConsortiumMIB.txt */
