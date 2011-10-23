--- ./ssh-dss.c	2009-08-08 20:54:21.000000000 -0400
+++ ../../pam_ssh_agent_auth-0.9.3.fixed/ssh-dss.c	2011-10-10 13:10:35.867387919 -0400
@@ -179,7 +179,7 @@
 
 	DSA_SIG_free(sig);
 
-	verbose("ssh_dss_verify: signature %s",
+	pam_ssh_auth_verbose("ssh_dss_verify: signature %s",
 	    ret == 1 ? "correct" : ret == 0 ? "incorrect" : "error");
 	return ret;
 }
