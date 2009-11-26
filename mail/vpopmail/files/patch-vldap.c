Description: Fix a crash when adding a virtual domain.
Forwarded: no
Author: Suzuki <xsuzu@yokohama.riken.jp>
Last-Update: 2009-11-26

--- a/vldap.c
+++ b/vldap.c
@@ -661,7 +661,7 @@
         }
     }
 
-    lm = (LDAPMod **)safe_malloc(sizeof(LDAPMod *) * 2);
+    lm = (LDAPMod **)safe_malloc(sizeof(LDAPMod *) * 3);
 
     lm[0] = (LDAPMod *)safe_malloc(sizeof(LDAPMod));
 
