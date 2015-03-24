--- src/sshguard.c.orig	2011-02-09 12:01:47 UTC
+++ src/sshguard.c
@@ -567,9 +567,13 @@ static void process_blacklisted_addresse
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
