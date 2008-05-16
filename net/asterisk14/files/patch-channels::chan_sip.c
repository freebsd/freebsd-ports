--- channels/chan_sip.c.orig	2008-03-18 16:42:59.000000000 +0200
+++ channels/chan_sip.c	2008-03-18 17:08:34.000000000 +0200
@@ -495,7 +495,7 @@
 #define DEFAULT_MOHINTERPRET    "default"
 #define DEFAULT_MOHSUGGEST      ""
 #define DEFAULT_VMEXTEN 	"asterisk"
-#define DEFAULT_CALLERID 	"asterisk"
+#define DEFAULT_CALLERID 	"Unknown"
 #define DEFAULT_NOTIFYMIME 	"application/simple-message-summary"
 #define DEFAULT_MWITIME 	10
 #define DEFAULT_ALLOWGUEST	TRUE
@@ -15873,6 +15881,9 @@
 	char *ext, *host;
 	char tmp[256];
 	char *dest = data;
+	char *secret = NULL;
+	char *md5secret = NULL;
+	char *authname = NULL;
 
 	oldformat = format;
 	if (!(format &= ((AST_FORMAT_MAX_AUDIO << 1) - 1))) {
@@ -15903,6 +15914,17 @@
 	if (host) {
 		*host++ = '\0';
 		ext = tmp;
+		secret = strchr(ext, ':');
+		if (secret) {
+			*secret++ = '\0';
+			md5secret = strchr(secret, ':');
+			if (md5secret) {
+				*md5secret++ = '\0';
+				authname = strchr(md5secret, ':');
+				if (authname)
+					*authname++ = '\0';
+			}
+		}
 	} else {
 		ext = strchr(tmp, '/');
 		if (ext) 
@@ -15933,6 +15955,14 @@
 		ast_string_field_set(p, username, ext);
 		ast_string_field_free(p, fullcontact);
 	}
+	if (secret && !ast_strlen_zero(secret))
+		ast_string_field_set(p, peersecret, secret);
+
+	if (md5secret && !ast_strlen_zero(md5secret))
+		ast_string_field_set(p, peermd5secret, md5secret);
+
+	if (authname && !ast_strlen_zero(authname))
+		ast_string_field_set(p, authname, authname);
 #if 0
 	printf("Setting up to call extension '%s' at '%s'\n", ext ? ext : "<none>", host);
 #endif
