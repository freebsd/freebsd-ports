--- ./ssh-rsa.c	2009-08-08 20:54:21.000000000 -0400
+++ ../../pam_ssh_agent_auth-0.9.3.fixed/ssh-rsa.c	2011-10-10 13:10:35.867387919 -0400
@@ -75,7 +75,7 @@
 	}
 	if (len < slen) {
 		u_int diff = slen - len;
-		verbose("slen %u > len %u", slen, len);
+		pam_ssh_auth_verbose("slen %u > len %u", slen, len);
 		memmove(sig + diff, sig, len);
 		memset(sig, 0, diff);
 	} else if (len > slen) {
@@ -148,7 +148,7 @@
 		return -1;
 	} else if (len < modlen) {
 		u_int diff = modlen - len;
-		verbose("ssh_rsa_verify: add padding: modlen %u > len %u",
+		pam_ssh_auth_verbose("ssh_rsa_verify: add padding: modlen %u > len %u",
 		    modlen, len);
 		sigblob = xrealloc(sigblob, 1, modlen);
 		memmove(sigblob + diff, sigblob, len);
@@ -169,7 +169,7 @@
 	memset(digest, 'd', sizeof(digest));
 	memset(sigblob, 's', len);
 	xfree(sigblob);
-	verbose("ssh_rsa_verify: signature %scorrect", (ret==0) ? "in" : "");
+	pam_ssh_auth_verbose("ssh_rsa_verify: signature %scorrect", (ret==0) ? "in" : "");
 	return ret;
 }
