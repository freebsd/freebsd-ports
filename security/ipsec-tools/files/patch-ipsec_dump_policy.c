--- src/libipsec/ipsec_dump_policy.c.orig	2010-12-03 21:01:11.000000000 +0600
+++ src/libipsec/ipsec_dump_policy.c	2025-02-09 15:01:50.443167000 +0700
@@ -77,8 +77,8 @@ ipsec_dump_policy(policy, delimiter)
  */
 char *
 ipsec_dump_policy(policy, delimiter)
-	ipsec_policy_t policy;
-	__ipsec_const char *delimiter;
+	c_ipsec_policy_t policy;
+	__ipsec_nconst char *delimiter;
 {
 	return ipsec_dump_policy1(policy, delimiter, 0);
 }
