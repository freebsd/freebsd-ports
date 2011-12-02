diff -r a8c2e04307c6 src/auth/passdb-vpopmail.c
--- src/auth/passdb-vpopmail.c	Wed Nov 23 19:04:15 2011 +0200
+++ src/auth/passdb-vpopmail.c	Fri Dec 02 23:39:55 2011 +0200
@@ -75,7 +75,8 @@
 		password = NULL;
 		*result_r = PASSDB_RESULT_USER_DISABLED;
 	} else {
-		if (vpw->pw_clear_passwd != NULL) {
+		if (vpw->pw_clear_passwd != NULL &&
+		    *vpw->pw_clear_passwd != '\0') {
 			password = t_strdup_noconst(vpw->pw_clear_passwd);
 			*cleartext = TRUE;
 		} else if (!*cleartext)
@@ -120,7 +121,7 @@
 	enum passdb_result result;
 	const char *scheme, *tmp_pass;
 	char *crypted_pass;
-	bool cleartext;
+	bool cleartext = FALSE;
 	int ret;
 
 	crypted_pass = vpopmail_password_lookup(request, &cleartext, &result);
