--- kdc/kdc_util.c.orig	Wed Oct 11 17:33:12 2006
+++ kdc/kdc_util.c	Wed Apr  4 13:53:04 2007
@@ -404,6 +404,7 @@
 
 	krb5_db_free_principal(kdc_context, &server, nprincs);
 	if (!krb5_unparse_name(kdc_context, ticket->server, &sname)) {
+	    limit_string(sname);
 	    krb5_klog_syslog(LOG_ERR,"TGS_REQ: UNKNOWN SERVER: server='%s'",
 			     sname);
 	    free(sname);
