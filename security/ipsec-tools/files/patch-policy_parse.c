--- src/libipsec/policy_parse.c.orig	2012-08-23 11:12:33.000000000 +0000
+++ src/libipsec/policy_parse.c	2025-02-09 07:02:38.738230000 +0000
@@ -2262,7 +2262,7 @@ ipsec_set_policy(msg, msglen)
 
 ipsec_policy_t
 ipsec_set_policy(msg, msglen)
-	__ipsec_const char *msg;
+	__ipsec_nconst char *msg;
 	int msglen;
 {
 	caddr_t policy;
