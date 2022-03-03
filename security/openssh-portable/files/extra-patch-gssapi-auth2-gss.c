--- auth2-gss.c.orig	2022-03-03 10:56:35.668672000 -0800
+++ auth2-gss.c	2022-03-03 11:03:16.048838000 -0800
@@ -59,7 +59,7 @@ static int input_gssapi_errtok(int, u_int32_t, struct 
  * The 'gssapi_keyex' userauth mechanism.
  */
 static int
-userauth_gsskeyex(struct ssh *ssh)
+userauth_gsskeyex(struct ssh *ssh, const char *method)
 {
 	Authctxt *authctxt = ssh->authctxt;
 	int r, authenticated = 0;
@@ -373,6 +373,7 @@ input_gssapi_mic(int type, u_int32_t plen, struct ssh 
 
 Authmethod method_gsskeyex = {
 	"gssapi-keyex",
+	NULL,
 	userauth_gsskeyex,
 	&options.gss_authentication
 };
