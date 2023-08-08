--- kadmin/server.c.orig	2022-09-15 16:54:19.000000000 -0700
+++ kadmin/server.c	2022-11-24 08:26:55.919761000 -0800
@@ -787,7 +787,9 @@
 	ret = krb5_read_priv_message(contextp, ac, &fd, &params);
 	if(ret)
 	    krb5_err(contextp, 1, ret, "krb5_read_priv_message");
-	_kadm5_unmarshal_params(contextp, &params, &realm_params);
+	ret = _kadm5_unmarshal_params(contextp, &params, &realm_params);
+	if(ret)
+	    krb5_err(contextp, 1, ret, "_kadm5_unmarshal_params");
     }
 
     initial = ticket->ticket.flags.initial;
