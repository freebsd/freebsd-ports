--- ntlm.c.orig	Mon Aug 15 12:05:33 2005
+++ ntlm.c	Tue Aug 16 19:33:37 2005
@@ -70,13 +70,14 @@
 
 	int len = unbase64(t2_buf, buf, TYPE2_BUF_SIZE);
 	int i;
+	ntlm_type2 *t2;
 
 	if (len <= 0) {
 		message("parse_type2: failed to decode the message\n");
 		return -1;
 	}
 
-	ntlm_type2 *t2 = (ntlm_type2 *)t2_buf;
+	t2 = (ntlm_type2 *)t2_buf;
 
 	if (strcmp(t2->signature, "NTLMSSP") != 0) {
 		message("parse_type2: Signature did not match\n");
