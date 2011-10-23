--- ./secure_filename.c	2009-08-08 20:54:21.000000000 -0400
+++ ../../pam_ssh_agent_auth-0.9.3.fixed/secure_filename.c	2011-10-10 13:10:35.867387919 -0400
@@ -80,7 +80,7 @@
 	int comparehome = 0;
 	struct stat st;
 
-    verbose("secure_filename: checking for uid: %u", uid);
+    pam_ssh_auth_verbose("secure_filename: checking for uid: %u", uid);
 
 	if (realpath(file, buf) == NULL) {
 		snprintf(err, errlen, "realpath %s failed: %s", file,
@@ -107,7 +107,7 @@
 		}
 		strlcpy(buf, cp, sizeof(buf));
 
-		verbose("secure_filename: checking '%s'", buf);
+		pam_ssh_auth_verbose("secure_filename: checking '%s'", buf);
 		if (stat(buf, &st) < 0 ||
 		    (st.st_uid != 0 && st.st_uid != uid) ||
 		    (st.st_mode & 022) != 0) {
@@ -118,7 +118,7 @@
 
 		/* If are passed the homedir then we can stop */
 		if (comparehome && strcmp(homedir, buf) == 0) {
-			verbose("secure_filename: terminating check at '%s'",
+			pam_ssh_auth_verbose("secure_filename: terminating check at '%s'",
 			    buf);
 			break;
 		}
