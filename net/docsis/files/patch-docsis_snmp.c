--- docsis_snmp.c.orig	Fri Jul  5 14:56:11 2002
+++ docsis_snmp.c	Fri Jul  5 14:56:53 2002
@@ -165,6 +165,7 @@
     if (snmp_set_var_objid(vp, objid, vp->name_length))
         return -1;
 
+    badtype = 0;
     len = PACKET_LENGTH;
     switch((short)vp->type){
     case ASN_INTEGER:
