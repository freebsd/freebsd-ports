--- agent/mibgroup/utilities/iquery.c.orig	2009-01-25 17:44:17.000000000 +0900
+++ agent/mibgroup/utilities/iquery.c	2009-01-25 17:47:04.000000000 +0900
@@ -186,7 +186,7 @@
         ss->securityEngineIDLen = engIDLen;
         if ( version == SNMP_VERSION_3 ) {
             ss->securityNameLen = strlen(secName);
-            memdup(&(ss->securityName), (u_char*)secName, ss->securityNameLen);
+            memdup((u_char**)&(ss->securityName), (u_char*)secName, ss->securityNameLen);
         } else {
             memdup( &(ss->community), secName, strlen(secName));
             ss->community_len = strlen(secName);
