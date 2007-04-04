--- kadmin/server/server_stubs.c.orig	Thu Apr 13 11:58:56 2006
+++ kadmin/server/server_stubs.c	Wed Apr  4 13:53:04 2007
@@ -14,6 +14,7 @@
 #include <arpa/inet.h>  /* inet_ntoa */
 #include <adm_proto.h>  /* krb5_klog_syslog */
 #include "misc.h"
+#include <string.h>
 
 #define LOG_UNAUTH  "Unauthorized request: %s, %s, client=%s, service=%s, addr=%s"
 #define	LOG_DONE    "Request: %s, %s, %s, client=%s, service=%s, addr=%s"
@@ -237,6 +238,61 @@
      return 0;
 }
 
+static int
+log_unauth(
+    char *op,
+    char *target,
+    gss_buffer_t client,
+    gss_buffer_t server,
+    struct svc_req *rqstp)
+{
+    size_t tlen, clen, slen;
+    char *tdots, *cdots, *sdots;
+
+    tlen = strlen(target);
+    trunc_name(&tlen, &tdots);
+    clen = client->length;
+    trunc_name(&clen, &cdots);
+    slen = server->length;
+    trunc_name(&slen, &sdots);
+
+    return krb5_klog_syslog(LOG_NOTICE,
+			    "Unauthorized request: %s, %.*s%s, "
+			    "client=%.*s%s, service=%.*s%s, addr=%s",
+			    op, tlen, target, tdots,
+			    clen, client->value, cdots,
+			    slen, server->value, sdots,
+			    inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+}
+
+static int
+log_done(
+    char *op,
+    char *target,
+    char *errmsg,
+    gss_buffer_t client,
+    gss_buffer_t server,
+    struct svc_req *rqstp)
+{
+    size_t tlen, clen, slen;
+    char *tdots, *cdots, *sdots;
+
+    tlen = strlen(target);
+    trunc_name(&tlen, &tdots);
+    clen = client->length;
+    trunc_name(&clen, &cdots);
+    slen = server->length;
+    trunc_name(&slen, &sdots);
+
+    return krb5_klog_syslog(LOG_NOTICE,
+			    "Request: %s, %.*s%s, %s, "
+			    "client=%.*s%s, service=%.*s%s, addr=%s",
+			    op, tlen, target, tdots, errmsg,
+			    clen, client->value, cdots,
+			    slen, server->value, sdots,
+			    inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+}
+
 generic_ret *
 create_principal_2_svc(cprinc_arg *arg, struct svc_req *rqstp)
 {
@@ -275,9 +331,8 @@
 	|| kadm5int_acl_impose_restrictions(handle->context,
 				   &arg->rec, &arg->mask, rp)) {
 	 ret.code = KADM5_AUTH_ADD;
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_create_principal",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth("kadm5_create_principal", prime_arg,
+		    &client_name, &service_name, rqstp);
     } else {
 	 ret.code = kadm5_create_principal((void *)handle,
 						&arg->rec, arg->mask,
@@ -287,10 +342,8 @@
 	 else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	 krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_create_principal",
-		prime_arg, errmsg,
-		client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_done("kadm5_create_principal", prime_arg, errmsg,
+		  &client_name, &service_name, rqstp);
 
 	 /* no need to check for NULL. Even if it is NULL, atleast error_code will be returned */
     }
@@ -341,9 +394,8 @@
 	|| kadm5int_acl_impose_restrictions(handle->context,
 				   &arg->rec, &arg->mask, rp)) {
 	 ret.code = KADM5_AUTH_ADD;
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_create_principal",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth("kadm5_create_principal", prime_arg,
+		    &client_name, &service_name, rqstp);
     } else {
 	 ret.code = kadm5_create_principal_3((void *)handle,
 					     &arg->rec, arg->mask,
@@ -355,10 +407,8 @@
 	 else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	 krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_create_principal",
-		prime_arg, errmsg,
-		client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_done("kadm5_create_principal", prime_arg, errmsg,
+		  &client_name, &service_name, rqstp);
 
 	 /* no need to check for NULL. Even if it is NULL, atleast error_code will be returned */
     }
@@ -406,9 +456,8 @@
 	|| !kadm5int_acl_check(handle->context, rqst2name(rqstp), ACL_DELETE,
 		      arg->princ, NULL)) {
 	 ret.code = KADM5_AUTH_DELETE;
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_delete_principal",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth("kadm5_delete_principal", prime_arg,
+		    &client_name, &service_name, rqstp);
     } else {
 	 ret.code = kadm5_delete_principal((void *)handle, arg->princ);
 	 if( ret.code == 0 )
@@ -416,10 +465,8 @@
 	 else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	 krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_delete_principal",
-			  prime_arg, errmsg,
-			  client_name.value, service_name.value,
-			  inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_done("kadm5_delete_principal", prime_arg, errmsg,
+		  &client_name, &service_name, rqstp);
 
 	 /* no need to check for NULL. Even if it is NULL, atleast error_code will be returned */
     }
@@ -469,9 +516,8 @@
 	|| kadm5int_acl_impose_restrictions(handle->context,
 				   &arg->rec, &arg->mask, rp)) {
 	 ret.code = KADM5_AUTH_MODIFY;
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_modify_principal",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth("kadm5_modify_principal", prime_arg,
+		    &client_name, &service_name, rqstp);
     } else {
 	 ret.code = kadm5_modify_principal((void *)handle, &arg->rec,
 						arg->mask);
@@ -480,10 +526,8 @@
 	 else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	 krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_modify_principal",
-			  prime_arg, errmsg,
-			  client_name.value, service_name.value,
-			  inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_done("kadm5_modify_principal", prime_arg, errmsg,
+		  &client_name, &service_name, rqstp);
 
 	 /* no need to check for NULL. Even if it is NULL, atleast error_code will be returned */
     }
@@ -546,9 +590,8 @@
     } else
 	 ret.code = KADM5_AUTH_INSUFFICIENT;
     if (ret.code != KADM5_OK) {
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_rename_principal",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth("kadm5_rename_principal", prime_arg,
+		    &client_name, &service_name, rqstp);
     } else {
 	 ret.code = kadm5_rename_principal((void *)handle, arg->src,
 						arg->dest);
@@ -557,10 +600,8 @@
 	 else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	 krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_rename_principal",
-		prime_arg, errmsg,
-		client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_done("kadm5_rename_principal", prime_arg, errmsg,
+		  &client_name, &service_name, rqstp);
     }
     free_server_handle(handle);
     free(prime_arg1);
@@ -614,9 +655,8 @@
 					       arg->princ,
 					       NULL))) {
 	 ret.code = KADM5_AUTH_GET;
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, funcname,
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth(funcname, prime_arg,
+		    &client_name, &service_name, rqstp);
     } else {
 	 if (handle->api_version == KADM5_API_VERSION_1) {
 	      ret.code  = kadm5_get_principal_v1((void *)handle,
@@ -636,11 +676,8 @@
 	 else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	 krb5_klog_syslog(LOG_NOTICE, LOG_DONE, funcname,
-		prime_arg,  
-		errmsg,
-		client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_done(funcname, prime_arg, errmsg,
+		  &client_name, &service_name, rqstp);
 
     }
     free_server_handle(handle);
@@ -688,9 +725,8 @@
 					      NULL,
 					      NULL)) {
 	 ret.code = KADM5_AUTH_LIST;
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_get_principals",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth("kadm5_get_principals", prime_arg,
+		    &client_name, &service_name, rqstp);
     } else {
 	 ret.code  = kadm5_get_principals((void *)handle,
 					       arg->exp, &ret.princs,
@@ -700,11 +736,8 @@
 	 else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	 krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_get_principals",
-		prime_arg,  
-		errmsg,
-		client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_done("kadm5_get_principals", prime_arg, errmsg,
+		  &client_name, &service_name, rqstp);
 
     }
     free_server_handle(handle);
@@ -755,9 +788,8 @@
 	 ret.code = kadm5_chpass_principal((void *)handle, arg->princ,
 						arg->pass);
     } else {
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_chpass_principal",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth("kadm5_chpass_principal", prime_arg,
+		    &client_name, &service_name, rqstp);
 	 ret.code = KADM5_AUTH_CHANGEPW;
     }
 
@@ -767,10 +799,8 @@
 	 else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_chpass_principal", 
-	       prime_arg, errmsg,
-	       client_name.value, service_name.value,
-	       inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	log_done("kadm5_chpass_principal", prime_arg, errmsg,
+		 &client_name, &service_name, rqstp);
     }
 
     free_server_handle(handle);
@@ -828,9 +858,8 @@
 					     arg->ks_tuple,
 					     arg->pass);
     } else {
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_chpass_principal",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth("kadm5_chpass_principal", prime_arg,
+		    &client_name, &service_name, rqstp);
 	 ret.code = KADM5_AUTH_CHANGEPW;
     }
 
@@ -840,10 +869,8 @@
 	else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_chpass_principal", 
-	       prime_arg, errmsg, 
-	       client_name.value, service_name.value,
-	       inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	log_done("kadm5_chpass_principal", prime_arg, errmsg,
+		 &client_name, &service_name, rqstp);
     }
 
     free_server_handle(handle);
@@ -892,9 +919,8 @@
 	 ret.code = kadm5_setv4key_principal((void *)handle, arg->princ,
 					     arg->keyblock);
     } else {
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_setv4key_principal",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth("kadm5_setv4key_principal", prime_arg,
+		    &client_name, &service_name, rqstp);
 	 ret.code = KADM5_AUTH_SETKEY;
     }
 
@@ -904,10 +930,8 @@
 	else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_setv4key_principal", 
-	       prime_arg, errmsg, 
-	       client_name.value, service_name.value,
-	       inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	log_done("kadm5_setv4key_principal", prime_arg, errmsg,
+		 &client_name, &service_name, rqstp);
     }
 
     free_server_handle(handle);
@@ -956,9 +980,8 @@
 	 ret.code = kadm5_setkey_principal((void *)handle, arg->princ,
 					   arg->keyblocks, arg->n_keys);
     } else {
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_setkey_principal",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth("kadm5_setkey_principal", prime_arg,
+		    &client_name, &service_name, rqstp);
 	 ret.code = KADM5_AUTH_SETKEY;
     }
 
@@ -968,10 +991,8 @@
 	else
 	    errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_setkey_principal", 
-	       prime_arg, errmsg, 
-	       client_name.value, service_name.value,
-	       inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	log_done("kadm5_setkey_principal", prime_arg, errmsg,
+		 &client_name, &service_name, rqstp);
     }
 
     free_server_handle(handle);
@@ -1023,9 +1044,8 @@
 					     arg->ks_tuple,
 					     arg->keyblocks, arg->n_keys);
     } else {
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_setkey_principal",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth("kadm5_setkey_principal", prime_arg,
+		    &client_name, &service_name, rqstp);
 	 ret.code = KADM5_AUTH_SETKEY;
     }
 
@@ -1035,10 +1055,8 @@
 	else
 	    errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_setkey_principal", 
-	       prime_arg, errmsg, 
-	       client_name.value, service_name.value,
-	       inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	log_done("kadm5_setkey_principal", prime_arg, errmsg,
+		 &client_name, &service_name, rqstp);
     }
 
     free_server_handle(handle);
@@ -1097,9 +1115,8 @@
 	 ret.code = kadm5_randkey_principal((void *)handle, arg->princ,
 					    &k, &nkeys);
     } else {
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, funcname,
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth(funcname, prime_arg,
+		    &client_name, &service_name, rqstp);
 	 ret.code = KADM5_AUTH_CHANGEPW;
     }
 
@@ -1119,10 +1136,8 @@
 	else
 	    errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	krb5_klog_syslog(LOG_NOTICE, LOG_DONE, funcname,
-	       prime_arg, errmsg, 
-	       client_name.value, service_name.value,
-	       inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	log_done(funcname, prime_arg, errmsg,
+		 &client_name, &service_name, rqstp);
     }
     free_server_handle(handle);
     free(prime_arg);
@@ -1185,9 +1200,8 @@
 					      arg->ks_tuple,
 					      &k, &nkeys);
     } else {
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, funcname,
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth(funcname, prime_arg,
+		    &client_name, &service_name, rqstp);
 	 ret.code = KADM5_AUTH_CHANGEPW;
     }
 
@@ -1207,10 +1221,8 @@
 	else
 	    errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	krb5_klog_syslog(LOG_NOTICE, LOG_DONE, funcname,
-	       prime_arg, errmsg, 
-	       client_name.value, service_name.value,
-	       inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	log_done(funcname, prime_arg, errmsg,
+		 &client_name, &service_name, rqstp);
     }
     free_server_handle(handle);
     free(prime_arg);
@@ -1253,10 +1265,9 @@
 					      rqst2name(rqstp),
 					      ACL_ADD, NULL, NULL)) {
 	 ret.code = KADM5_AUTH_ADD;
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_create_policy",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
-	 
+	 log_unauth("kadm5_create_policy", prime_arg,
+		    &client_name, &service_name, rqstp);
+
     } else {
 	 ret.code = kadm5_create_policy((void *)handle, &arg->rec,
 					     arg->mask);
@@ -1265,11 +1276,9 @@
 	 else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	 krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_create_policy",
-		((prime_arg == NULL) ? "(null)" : prime_arg),
-		errmsg, 
-		client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));	 
+	 log_done("kadm5_create_policy",
+		  ((prime_arg == NULL) ? "(null)" : prime_arg), errmsg,
+		  &client_name, &service_name, rqstp);
     }
     free_server_handle(handle);
     gss_release_buffer(&minor_stat, &client_name);
@@ -1310,9 +1319,8 @@
     if (CHANGEPW_SERVICE(rqstp) || !kadm5int_acl_check(handle->context,
 					      rqst2name(rqstp),
 					      ACL_DELETE, NULL, NULL)) {
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_delete_policy",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth("kadm5_delete_policy", prime_arg,
+		    &client_name, &service_name, rqstp);
 	 ret.code = KADM5_AUTH_DELETE;
     } else {
 	 ret.code = kadm5_delete_policy((void *)handle, arg->name);
@@ -1321,11 +1329,9 @@
 	 else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	 krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_delete_policy",
-		((prime_arg == NULL) ? "(null)" : prime_arg),
-		errmsg, 
-		client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));	 
+	 log_done("kadm5_delete_policy",
+		  ((prime_arg == NULL) ? "(null)" : prime_arg), errmsg,
+		  &client_name, &service_name, rqstp);
     }
     free_server_handle(handle);
     gss_release_buffer(&minor_stat, &client_name);
@@ -1366,9 +1372,8 @@
     if (CHANGEPW_SERVICE(rqstp) || !kadm5int_acl_check(handle->context,
 					      rqst2name(rqstp),
 					      ACL_MODIFY, NULL, NULL)) {
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_modify_policy",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth("kadm5_modify_policy", prime_arg,
+		    &client_name, &service_name, rqstp);
 	 ret.code = KADM5_AUTH_MODIFY;
     } else {
 	 ret.code = kadm5_modify_policy((void *)handle, &arg->rec,
@@ -1378,11 +1383,9 @@
 	 else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	 krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_modify_policy",
-		((prime_arg == NULL) ? "(null)" : prime_arg),	    
-		errmsg, 
-		client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));	
+	 log_done("kadm5_modify_policy",
+		  ((prime_arg == NULL) ? "(null)" : prime_arg), errmsg,
+		  &client_name, &service_name, rqstp);
     }
     free_server_handle(handle);
     gss_release_buffer(&minor_stat, &client_name);
@@ -1464,15 +1467,12 @@
 	 else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	 krb5_klog_syslog(LOG_NOTICE, LOG_DONE, funcname,
-		((prime_arg == NULL) ? "(null)" : prime_arg),
-		errmsg, 
-		client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));	 
+	 log_done(funcname,
+		  ((prime_arg == NULL) ? "(null)" : prime_arg), errmsg,
+		  &client_name, &service_name, rqstp);
     } else {
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, funcname,
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth(funcname, prime_arg,
+		    &client_name, &service_name, rqstp);
     }
     free_server_handle(handle);
     gss_release_buffer(&minor_stat, &client_name);
@@ -1517,9 +1517,8 @@
 					      rqst2name(rqstp),
 					      ACL_LIST, NULL, NULL)) {
 	 ret.code = KADM5_AUTH_LIST;
-	 krb5_klog_syslog(LOG_NOTICE, LOG_UNAUTH, "kadm5_get_policies",
-		prime_arg, client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_unauth("kadm5_get_policies", prime_arg,
+		    &client_name, &service_name, rqstp);
     } else {
 	 ret.code  = kadm5_get_policies((void *)handle,
 					       arg->exp, &ret.pols,
@@ -1529,11 +1528,8 @@
 	 else
 	     errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-	 krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_get_policies",
-		prime_arg,  
-		errmsg, 
-		client_name.value, service_name.value,
-		inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+	 log_done("kadm5_get_policies", prime_arg, errmsg,
+		  &client_name, &service_name, rqstp);
     }
     free_server_handle(handle);
     gss_release_buffer(&minor_stat, &client_name);
@@ -1573,11 +1569,8 @@
      else
 	 errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
 
-     krb5_klog_syslog(LOG_NOTICE, LOG_DONE, "kadm5_get_privs",
-	    client_name.value, 
-	    errmsg, 
-	    client_name.value, service_name.value,
-	    inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr));
+     log_done("kadm5_get_privs", client_name.value, errmsg,
+	      &client_name, &service_name, rqstp);
 
      free_server_handle(handle);
      gss_release_buffer(&minor_stat, &client_name);
@@ -1594,6 +1587,8 @@
      kadm5_server_handle_t	handle;
      OM_uint32			minor_stat;
      char                       *errmsg = 0;
+     size_t clen, slen;
+     char *cdots, *sdots;
 
      xdr_free(xdr_generic_ret, &ret);
 
@@ -1612,14 +1607,22 @@
 
      if (ret.code != 0)
 	 errmsg = krb5_get_error_message(handle ? handle->context : NULL, ret.code);
-     krb5_klog_syslog(LOG_NOTICE, LOG_DONE ", flavor=%d",
-	    (ret.api_version == KADM5_API_VERSION_1 ?
-	     "kadm5_init (V1)" : "kadm5_init"),
-	    client_name.value,
-	    (ret.code == 0) ? "success" : errmsg,
-	    client_name.value, service_name.value,
-	    inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr),
-	    rqstp->rq_cred.oa_flavor);
+     else
+	 errmsg = "success";
+
+     clen = client_name.length;
+     trunc_name(&clen, &cdots);
+     slen = service_name.length;
+     trunc_name(&slen, &sdots);
+     krb5_klog_syslog(LOG_NOTICE, "Request: %s, %.*s%s, %s, "
+		      "client=%.*s%s, service=%.*s%s, addr=%s, flavor=%d",
+		      (ret.api_version == KADM5_API_VERSION_1 ?
+		       "kadm5_init (V1)" : "kadm5_init"),
+		      clen, client_name.value, cdots, errmsg,
+		      clen, client_name.value, cdots,
+		      slen, service_name.value, sdots,
+		      inet_ntoa(rqstp->rq_xprt->xp_raddr.sin_addr),
+		      rqstp->rq_cred.oa_flavor);
      gss_release_buffer(&minor_stat, &client_name);
      gss_release_buffer(&minor_stat, &service_name);
 	    
