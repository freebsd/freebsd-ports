--- agent/agent_registry.c.orig	2008-08-24 23:24:04.944441100 +0900
+++ agent/agent_registry.c	2008-08-24 23:25:37.996227686 +0900
@@ -532,7 +532,8 @@
 	
 	    if (next && (next->namelen  == new_sub->namelen) &&
 		(next->priority == new_sub->priority)) {
-                netsnmp_assert(!"registration != duplicate"); /* always false */
+		if (new_sub->namelen != 1) /* ignore root OID dups */
+                  netsnmp_assert(!"registration != duplicate"); /* always false */
 		return MIB_DUPLICATE_REGISTRATION;
 	    }
 
