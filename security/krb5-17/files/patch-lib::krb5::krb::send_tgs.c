--- lib/krb5/krb/send_tgs.c.orig	Thu May 13 12:27:59 2004
+++ lib/krb5/krb/send_tgs.c	Wed Sep  1 11:46:52 2004
@@ -269,6 +269,8 @@
 	    if (!tcp_only) {
 		krb5_error *err_reply;
 		retval = decode_krb5_error(&rep->response, &err_reply);
+		if (retval)
+		    goto send_tgs_error_3;
 		if (err_reply->error == KRB_ERR_RESPONSE_TOO_BIG) {
 		    tcp_only = 1;
 		    krb5_free_error(context, err_reply);
@@ -277,6 +279,8 @@
 		    goto send_again;
 		}
 		krb5_free_error(context, err_reply);
+	    send_tgs_error_3:
+		;
 	    }
 	    rep->message_type = KRB5_ERROR;
 	} else if (krb5_is_tgs_rep(&rep->response))
