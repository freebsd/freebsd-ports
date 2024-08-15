--- src/users.c.orig	2024-08-15 14:34:02 UTC
+++ src/users.c
@@ -211,6 +211,24 @@ struct mt_credentials *find_user(char *username) {
 	return NULL;
 }
 
+#if OPENSSL_VERSION_NUMBER < 0x030000000 // less than 3.0.0
+/*
+ * Filter out colons from the decoded string.
+ * By default, the OPENSSL_buf2hexstr function in OpenSSL 1.1
+ * uses colons as a byte separator, and this cannot be overridden.
+ */
+static void remove_colons(char *s) {
+	const char *p = s;
+	char *q = s;
+	while (*p != '\0') {
+		*q = *p++;
+		q += (*q != ':');
+	}
+
+	*q = '\0';
+}
+#endif
+
 int add_user(const char *username, const char *password) {
 	FILE *rfile;
 	FILE *wfile;
@@ -289,12 +307,27 @@ int add_user(const char *username, const char *passwor
 				continue;
 			}
 			fprintf(wfile, "%s:", username);
+#if OPENSSL_VERSION_NUMBER < 0x030000000 // less than 3.0.0
+			char *output;
+			output = OPENSSL_buf2hexstr(newhash, MT_CRED_HASHLEN);
+			remove_colons(output);
+#else
 			char output[MT_CRED_HASHLEN * 2 + 1];
 			OPENSSL_buf2hexstr_ex(output, sizeof(output), NULL, newhash, MT_CRED_HASHLEN, '\0');
+#endif
 			fputs(output, wfile);
 			fputs(":", wfile);
+#if OPENSSL_VERSION_NUMBER < 0x030000000 // less than 3.0.0
+			OPENSSL_free(output);
+			output = OPENSSL_buf2hexstr(newsalt, MT_CRED_SALTLEN);
+			remove_colons(output);
+#else
 			OPENSSL_buf2hexstr_ex(output, sizeof(output), NULL, newsalt, MT_CRED_SALTLEN, '\0');
+#endif
 			fputs(output, wfile);
+#if OPENSSL_VERSION_NUMBER < 0x030000000 // less than 3.0.0
+			OPENSSL_free(output);
+#endif
 			fputs("\n", wfile);
 			found = 1;
 		} else {
@@ -306,12 +339,27 @@ int add_user(const char *username, const char *passwor
 	if (!found && password != NULL) {
 		// Write username, salt, and hashed password to the file
 		fprintf(wfile, "%s:", username);
+#if OPENSSL_VERSION_NUMBER < 0x030000000 // less than 3.0.0
+		char *output;
+		output = OPENSSL_buf2hexstr(newhash, MT_CRED_HASHLEN);
+		remove_colons(output);
+#else
 		char output[MT_CRED_HASHLEN * 2 + 1];
 		OPENSSL_buf2hexstr_ex(output, sizeof(output), NULL, newhash, MT_CRED_HASHLEN, '\0');
+#endif
 		fputs(output, wfile);
 		fputs(":", wfile);
+#if OPENSSL_VERSION_NUMBER < 0x030000000 // less than 3.0.0
+		OPENSSL_free(output);
+		output = OPENSSL_buf2hexstr(newsalt, MT_CRED_SALTLEN);
+		remove_colons(output);
+#else
 		OPENSSL_buf2hexstr_ex(output, sizeof(output), NULL, newsalt, MT_CRED_SALTLEN, '\0');
+#endif
 		fputs(output, wfile);
+#if OPENSSL_VERSION_NUMBER < 0x030000000 // less than 3.0.0
+		OPENSSL_free(output);
+#endif
 		fputs("\n", wfile);
 	}
 
@@ -327,4 +375,4 @@ int add_user(const char *username, const char *passwor
 	}
 
 	return found ? 2 : 1;
-}
\ No newline at end of file
+}
