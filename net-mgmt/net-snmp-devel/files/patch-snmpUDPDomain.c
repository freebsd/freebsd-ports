--- snmplib/snmpUDPDomain.c.orig	2008-01-11 21:53:12.214973877 +0900
+++ snmplib/snmpUDPDomain.c	2008-01-11 21:54:13.707245200 +0900
@@ -105,7 +105,7 @@
                     inet_ntoa(addr_pair->local_addr));
         } else {
             sprintf(tmp, "UDP: [%s]->", inet_ntoa(addr_pair->local_addr));
-            sprintf(tmp + strlen(tmp), "[%s]:%hd",
+            sprintf(tmp + strlen(tmp), "[%s]:%hu",
                     inet_ntoa(to->sin_addr), ntohs(to->sin_port));
         }
         return strdup(tmp);
