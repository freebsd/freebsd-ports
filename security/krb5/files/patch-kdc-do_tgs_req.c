--- kdc/do_tgs_req.c.orig	Fri Oct 13 14:08:07 2006
+++ kdc/do_tgs_req.c	Wed Apr  4 13:53:04 2007
@@ -491,28 +491,38 @@
 	newtransited = 1;
     }
     if (!isflagset (request->kdc_options, KDC_OPT_DISABLE_TRANSITED_CHECK)) {
+	unsigned int tlen;
+	char *tdots;
+
 	errcode = krb5_check_transited_list (kdc_context,
 					     &enc_tkt_reply.transited.tr_contents,
 					     krb5_princ_realm (kdc_context, header_ticket->enc_part2->client),
 					     krb5_princ_realm (kdc_context, request->server));
+	tlen = enc_tkt_reply.transited.tr_contents.length;
+	tdots = tlen > 125 ? "..." : "";
+	tlen = tlen > 125 ? 125 : tlen;
+
 	if (errcode == 0) {
 	    setflag (enc_tkt_reply.flags, TKT_FLG_TRANSIT_POLICY_CHECKED);
 	} else if (errcode == KRB5KRB_AP_ERR_ILL_CR_TKT)
 	    krb5_klog_syslog (LOG_INFO,
-			      "bad realm transit path from '%s' to '%s' via '%.*s'",
+			      "bad realm transit path from '%s' to '%s' "
+			      "via '%.*s%s'",
 			      cname ? cname : "<unknown client>",
 			      sname ? sname : "<unknown server>",
-			      enc_tkt_reply.transited.tr_contents.length,
-			      enc_tkt_reply.transited.tr_contents.data);
+			      tlen,
+			      enc_tkt_reply.transited.tr_contents.data,
+			      tdots);
 	else {
 	    const char *emsg = krb5_get_error_message(kdc_context, errcode);
 	    krb5_klog_syslog (LOG_ERR,
-			      "unexpected error checking transit from '%s' to '%s' via '%.*s': %s",
+			      "unexpected error checking transit from "
+			      "'%s' to '%s' via '%.*s%s': %s",
 			      cname ? cname : "<unknown client>",
 			      sname ? sname : "<unknown server>",
-			      enc_tkt_reply.transited.tr_contents.length,
+			      tlen,
 			      enc_tkt_reply.transited.tr_contents.data,
-			      emsg);
+			      tdots, emsg);
 	    krb5_free_error_message(kdc_context, emsg);
 	}
     } else
@@ -542,6 +552,9 @@
 	if (!krb5_principal_compare(kdc_context, request->server, client2)) {
 		if ((errcode = krb5_unparse_name(kdc_context, client2, &tmp)))
 			tmp = 0;
+		if (tmp != NULL)
+		    limit_string(tmp);
+
 		krb5_klog_syslog(LOG_INFO,
 				 "TGS_REQ %s: 2ND_TKT_MISMATCH: "
 				 "authtime %d, %s for %s, 2nd tkt client %s",
@@ -816,6 +829,7 @@
 		krb5_klog_syslog(LOG_INFO,
 		       "TGS_REQ: issuing alternate <un-unparseable> TGT");
 	    } else {
+		limit_string(sname);
 		krb5_klog_syslog(LOG_INFO,
 		       "TGS_REQ: issuing TGT %s", sname);
 		free(sname);
