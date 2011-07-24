--- src/sshguard.c.orig	2010-08-09 08:44:15.000000000 +0200
+++ src/sshguard.c	2011-03-28 11:42:42.000000000 +0200
@@ -566,9 +566,13 @@
         /* terminate array list */
         addresses[i] = NULL;
         /* do block addresses of this kind */
-        if (fw_block_list(addresses, addrkind, service_codes) != FWALL_OK) {
-            sshguard_log(LOG_CRIT, "While blocking blacklisted addresses, the firewall refused to block!");
-        }
+        if (addresses[0] == NULL) {
+            sshguard_log(LOG_DEBUG, "No %s addresses in loaded blacklist.", (addrkind == ADDRKIND_IPv4) ? "IPv4" : "IPv6");
+        } else {
+            if (fw_block_list(addresses, addrkind, service_codes) != FWALL_OK) {
+                sshguard_log(LOG_CRIT, "While blocking blacklisted addresses, the firewall refused to block!");
+            }
+        } 
     }
     /* free temporary arrays */
     free(addresses);


