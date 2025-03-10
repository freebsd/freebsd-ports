--- src/libipsec/ipsec_get_policylen.c.orig	2007-07-18 12:07:50.000000000 +0000
+++ src/libipsec/ipsec_get_policylen.c	2025-02-09 07:40:22.545915000 +0000
@@ -48,7 +48,7 @@
 
 int
 ipsec_get_policylen(policy)
-	ipsec_policy_t policy;
+	c_ipsec_policy_t policy;
 {
 	return policy ? PFKEY_EXTLEN(policy) : -1;
 }
