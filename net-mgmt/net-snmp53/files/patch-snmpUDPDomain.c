--- snmplib/snmpUDPDomain.c.orig	Mon Jan 24 10:47:16 2005
+++ snmplib/snmpUDPDomain.c	Mon Jan 24 10:47:41 2005
@@ -88,7 +88,7 @@
     } else {
 	char tmp[64];
 
-        sprintf(tmp, "UDP: [%s]:%hd",
+        sprintf(tmp, "UDP: [%s]:%hu",
                 inet_ntoa(to->sin_addr), ntohs(to->sin_port));
         return strdup(tmp);
     }
