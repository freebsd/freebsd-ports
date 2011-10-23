--- ./key.c	2009-08-08 20:54:21.000000000 -0400
+++ ../../pam_ssh_agent_auth-0.9.3.fixed/key.c	2011-10-10 13:10:35.865388224 -0400
@@ -420,26 +420,26 @@
 	case KEY_DSA:
 		space = strchr(cp, ' ');
 		if (space == NULL) {
-			verbose("key_read: missing whitespace");
+			pam_ssh_auth_verbose("key_read: missing whitespace");
 			return -1;
 		}
 		*space = '\0';
 		type = key_type_from_name(cp);
 		*space = ' ';
 		if (type == KEY_UNSPEC) {
-			verbose("key_read: missing keytype");
+			pam_ssh_auth_verbose("key_read: missing keytype");
 			return -1;
 		}
 		cp = space+1;
 		if (*cp == '\0') {
-			verbose("key_read: short string");
+			pam_ssh_auth_verbose("key_read: short string");
 			return -1;
 		}
 		if (ret->type == KEY_UNSPEC) {
 			ret->type = type;
 		} else if (ret->type != type) {
 			/* is a key, but different type */
-			verbose("key_read: type mismatch");
+			pam_ssh_auth_verbose("key_read: type mismatch");
 			return -1;
 		}
 		len = 2*strlen(cp);
@@ -656,7 +656,7 @@
 	} else if (strcmp(name, "ssh-dss") == 0) {
 		return KEY_DSA;
 	}
-	verbose("key_type_from_name: unknown key type '%s'", name);
+	pam_ssh_auth_verbose("key_type_from_name: unknown key type '%s'", name);
 	return KEY_UNSPEC;
 }
 
@@ -677,7 +677,7 @@
 			return 0;
 		}
 	}
-	verbose("key names ok: [%s]", names);
+	pam_ssh_auth_verbose("key names ok: [%s]", names);
 	xfree(s);
 	return 1;
 }
