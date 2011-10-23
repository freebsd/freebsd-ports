--- ./pam_user_key_allowed2.c	2011-06-07 02:32:46.000000000 -0400
+++ ../../pam_ssh_agent_auth-0.9.3.fixed/pam_user_key_allowed2.c	2011-10-10 13:10:35.866387792 -0400
@@ -63,11 +63,11 @@
 	Key *found;
 	char *fp;
 
-	verbose("trying public key file %s", file);
+	pam_ssh_auth_verbose("trying public key file %s", file);
 
 	/* Fail not so quietly if file does not exist */
 	if (stat(file, &st) < 0) {
-        verbose("File not found: %s", file);
+        pam_ssh_auth_verbose("File not found: %s", file);
 		return 0;
 	}
 	/* Open the file containing the authorized keys. */
@@ -97,7 +97,7 @@
 		if (key_read(found, &cp) != 1) {
 			/* no key?  check if there are options for this key */
 			int quoted = 0;
-			verbose("user_key_allowed: check options: '%s'", cp);
+			pam_ssh_auth_verbose("user_key_allowed: check options: '%s'", cp);
 			key_options = cp;
 			for (; *cp && (quoted || (*cp != ' ' && *cp != '\t')); cp++) {
 				if (*cp == '\\' && cp[1] == '"')
@@ -109,7 +109,7 @@
 			for (; *cp == ' ' || *cp == '\t'; cp++)
 				;
 			if (key_read(found, &cp) != 1) {
-				verbose("user_key_allowed: advance: '%s'", cp);
+				pam_ssh_auth_verbose("user_key_allowed: advance: '%s'", cp);
 				/* still no key?  advance to next line*/
 				continue;
 			}
@@ -128,6 +128,6 @@
 	fclose(f);
 	key_free(found);
 	if (!found_key)
-		verbose("key not found");
+		pam_ssh_auth_verbose("key not found");
 	return found_key;
 }
