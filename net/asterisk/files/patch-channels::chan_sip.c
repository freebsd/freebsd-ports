--- channels/chan_sip.c.orig	Mon Dec 24 11:59:46 2007
+++ channels/chan_sip.c	Mon Dec 24 11:58:47 2007
@@ -493,7 +493,7 @@
 #define DEFAULT_MOHINTERPRET    "default"
 #define DEFAULT_MOHSUGGEST      ""
 #define DEFAULT_VMEXTEN 	"asterisk"
-#define DEFAULT_CALLERID 	"asterisk"
+#define DEFAULT_CALLERID 	"Unknown"
 #define DEFAULT_NOTIFYMIME 	"application/simple-message-summary"
 #define DEFAULT_MWITIME 	10
 #define DEFAULT_ALLOWGUEST	TRUE
@@ -3985,6 +3985,8 @@
 	ast_codec_pref_remove2(&tmp->nativeformats, ~i->usercapability);
 	fmt = ast_codec_pref_index_audio(&tmp->nativeformats, 0);
 
+	pbx_builtin_setvar_helper(tmp, "SIP_CODEC_USED", ast_getformatname(fmt));
+
 	/* If we have a prefcodec setting, we have an inbound channel that set a 
 	   preferred format for this call. Otherwise, we check the jointcapability
 	   We also check for vrtp. If it's not there, we are not allowed do any video anyway.
@@ -15845,6 +15847,9 @@
 	char *ext, *host;
 	char tmp[256];
 	char *dest = data;
+	char *secret = NULL;
+	char *md5secret = NULL;
+	char *authname = NULL;
 
 	if (!(p = sip_alloc(NULL, NULL, 0, SIP_INVITE))) {
 		ast_log(LOG_ERROR, "Unable to build sip pvt data for '%s' (Out of memory or socket error)\n", (char *)data);
@@ -15866,6 +15871,17 @@
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
@@ -15898,6 +15914,14 @@
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
