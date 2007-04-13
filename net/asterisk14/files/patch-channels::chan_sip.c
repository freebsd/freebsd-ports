--- channels/chan_sip.c.orig	Wed Mar 28 11:23:42 2007
+++ channels/chan_sip.c	Wed Mar 28 11:36:27 2007
@@ -484,7 +484,7 @@ static const struct cfsip_options {
 #define DEFAULT_MOHINTERPRET    "default"
 #define DEFAULT_MOHSUGGEST      ""
 #define DEFAULT_VMEXTEN 	"asterisk"
-#define DEFAULT_CALLERID 	"asterisk"
+#define DEFAULT_CALLERID 	"Unknown"
 #define DEFAULT_NOTIFYMIME 	"application/simple-message-summary"
 #define DEFAULT_MWITIME 	10
 #define DEFAULT_ALLOWGUEST	TRUE
@@ -3822,6 +3823,8 @@ static struct ast_channel *sip_new(struc
 	ast_codec_pref_remove2(&tmp->nativeformats, ~i->usercapability);
 	fmt = ast_codec_pref_index_audio(&tmp->nativeformats, 0);
 
+	pbx_builtin_setvar_helper(tmp, "SIP_CODEC_USED", ast_getformatname(fmt));
+
 	/* If we have a prefcodec setting, we have an inbound channel that set a 
 	   preferred format for this call. Otherwise, we check the jointcapability
 	   We also check for vrtp. If it's not there, we are not allowed do any video anyway.
@@ -11203,6 +11215,13 @@ static int build_reply_digest(struct sip
  		secret =  p->peersecret;
  		md5secret = p->peermd5secret;
  	}
+	/* No authentication. Try to get auth info from channel vars */
+	if (ast_strlen_zero(username))
+	{
+		username = pbx_builtin_getvar_helper(p->owner, "SIP_AUTH_NAME");
+		secret = pbx_builtin_getvar_helper(p->owner, "SIP_AUTH_SECRET");
+		md5secret = pbx_builtin_getvar_helper(p->owner, "SIP_AUTH_MD5SECRET");
+	}
 	if (ast_strlen_zero(username))	/* We have no authentication */
 		return -1;
 

