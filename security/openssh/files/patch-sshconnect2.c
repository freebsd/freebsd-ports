--- sshconnect2.c.orig	Tue Mar 26 16:58:46 2002
+++ sshconnect2.c	Fri May 24 08:08:54 2002
@@ -472,7 +472,7 @@
  * parse PASSWD_CHANGEREQ, prompt user and send SSH2_MSG_USERAUTH_REQUEST
  */
 void
-input_userauth_passwd_changereq(int type, uint32_t seqnr, void *ctxt)
+input_userauth_passwd_changereq(int type, u_int32_t seqnr, void *ctxt)
 {
 	Authctxt *authctxt = ctxt;
 	char *info, *lang, *password = NULL, *retype = NULL;
