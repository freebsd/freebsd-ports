--- stoken.c.orig	2021-07-01 20:58:46 UTC
+++ stoken.c
@@ -100,6 +100,7 @@ static int decrypt_stoken(struct openconnect_info *vpn
 
 	form.opts = opts;
 	form.message = _("Enter credentials to unlock software token.");
+	form.auth_id = "_rsa_unlock";
 
 	if (stoken_devid_required(vpninfo->stoken_ctx)) {
 		opt->type = OC_FORM_OPT_TEXT;
@@ -206,9 +207,10 @@ static int request_stoken_pin(struct openconnect_info 
 
 	form.opts = opts;
 	form.message = _("Enter software token PIN.");
+	form.auth_id = "_rsa_pin";
 
 	opt->type = OC_FORM_OPT_PASSWORD;
-	opt->name = (char *)"password";
+	opt->name = (char *)"pin";
 	opt->label = _("PIN:");
 	opt->flags = OC_FORM_OPT_NUMERIC;
 
