--- src/protocols/oscar/oscar.c.orig	2004-05-30 21:04:55.000000000 +0400
+++ src/protocols/oscar/oscar.c	2004-06-05 22:14:22.000000000 +0400
@@ -3019,6 +3019,7 @@
 	GError *err = NULL;
 	struct buddyinfo *bi;
 	const char *iconfile;
+	char *charset;
 
 	bi = g_hash_table_lookup(od->buddyinfo, gaim_normalize(account, userinfo->sn));
 	if (!bi) {
@@ -3110,10 +3112,11 @@
 		if (!args->msg || !args->msglen)
 			return 1;
 
-		tmp = g_convert(args->msg, args->msglen, "UTF-8", "ISO-8859-1", NULL, &convlen, &err);
+		charset = gaim_account_get_string(account, "plain_charset", "ISO-8859-1");		
+		tmp = g_convert(args->msg, args->msglen, "UTF-8", charset, NULL, &convlen, &err);
 		if (err) {
-			gaim_debug_info("oscar",
-					   "ISO-8859-1 IM conversion: %s\n", err->message);
+  			gaim_debug(GAIM_DEBUG_INFO, "oscar",
+ 					   "%s IM conversion: %s\n", charset, err->message);
 			tmp = g_strdup(_("(There was an error receiving this message)"));
 			g_error_free(err);
 		}
@@ -5133,6 +5136,8 @@
 	GError *err = NULL;
 	const char *iconfile = gaim_account_get_buddy_icon(gaim_connection_get_account(gc));
 	char *tmpmsg = NULL, *tmpmsg2 = NULL;
+ 	GaimAccount *account = gc->account;
+ 	char *charset;
 
 	if (dim && dim->connected) {
 		/* If we're directly connected, send a direct IM */
@@ -5233,7 +5238,8 @@
 		}
 		len = strlen(tmpmsg);
 
-		args.flags |= oscar_encoding_check(tmpmsg);
+		if(!(gaim_account_get_bool(account, "send_plain", FALSE)))
+			args.flags |= oscar_encoding_check(tmpmsg);
 		if (args.flags & AIM_IMFLAGS_UNICODE) {
 			gaim_debug_info("oscar", "Sending Unicode IM\n");
 			args.charset = 0x0002;
@@ -5272,7 +5278,10 @@
 		} else {
 			args.charset = 0x0000;
 			args.charsubset = 0x0000;
-			args.msg = tmpmsg;
+			charset = gaim_account_get_string(account, "plain_charset", "ISO-8859-1");
+			args.msg = g_convert(tmpmsg, len, charset, "UTF-8", NULL, &len, &err);
+			if (err) gaim_debug(GAIM_DEBUG_ERROR, "oscar",
+						   "conversion error: %s\n", err->message);
 		}
 		args.msglen = len;
 
@@ -7230,6 +7239,17 @@
 	option = gaim_account_option_int_new(_("Auth port"), "port", 5190);
 	prpl_info.protocol_options = g_list_append(prpl_info.protocol_options,
 											   option);
+	option = gaim_account_option_string_new(
+			_("Charset for plain text messages"),
+			"plain_charset", "ISO-8859-1");
+	prpl_info.protocol_options = g_list_append(prpl_info.protocol_options,
+			option);
+
+	option = gaim_account_option_bool_new(
+			_("Send messages in plain text"),
+			"send_plain", FALSE);
+	prpl_info.protocol_options = g_list_append(prpl_info.protocol_options,
+			option);
 
 	my_protocol = plugin;
 }
