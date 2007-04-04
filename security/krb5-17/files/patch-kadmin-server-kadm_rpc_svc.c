--- kadmin/server/kadm_rpc_svc.c.orig	Fri Mar 31 19:08:17 2006
+++ kadmin/server/kadm_rpc_svc.c	Wed Apr  4 13:53:04 2007
@@ -250,6 +250,8 @@
      krb5_data *c1, *c2, *realm;
      gss_buffer_desc gss_str;
      kadm5_server_handle_t handle;
+     size_t slen;
+     char *sdots;
 
      success = 0;
      handle = (kadm5_server_handle_t)global_server_handle;
@@ -274,6 +276,8 @@
      if (ret == 0)
 	  goto fail_name;
 
+     slen = gss_str.length;
+     trunc_name(&slen, &sdots);
      /*
       * Since we accept with GSS_C_NO_NAME, the client can authenticate
       * against the entire kdb.  Therefore, ensure that the service
@@ -296,8 +300,8 @@
 
 fail_princ:
      if (!success) {
-	 krb5_klog_syslog(LOG_ERR, "bad service principal %.*s",
-			  gss_str.length, gss_str.value);
+	 krb5_klog_syslog(LOG_ERR, "bad service principal %.*s%s",
+			  slen, gss_str.value, sdots);
      }
      gss_release_buffer(&min_stat, &gss_str);
      krb5_free_principal(kctx, princ);
