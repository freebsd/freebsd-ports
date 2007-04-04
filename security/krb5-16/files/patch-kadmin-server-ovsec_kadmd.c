--- kadmin/server/ovsec_kadmd.c.orig	Tue Jan  9 12:21:43 2007
+++ kadmin/server/ovsec_kadmd.c	Wed Apr  4 13:53:04 2007
@@ -992,6 +992,8 @@
      rpcproc_t proc;
      int i;
      const char *procname;
+     size_t clen, slen;
+     char *cdots, *sdots;
 
      client.length = 0;
      client.value = NULL;
@@ -1000,10 +1002,20 @@
 
      (void) gss_display_name(&minor, client_name, &client, &gss_type);
      (void) gss_display_name(&minor, server_name, &server, &gss_type);
-     if (client.value == NULL)
+     if (client.value == NULL) {
 	 client.value = "(null)";
-     if (server.value == NULL)
+	 clen = sizeof("(null)") -1;
+     } else {
+	 clen = client.length;
+     }
+     trunc_name(&clen, &cdots);
+     if (server.value == NULL) {
 	 server.value = "(null)";
+	 slen = sizeof("(null)") - 1;
+     } else {
+	 slen = server.length;
+     }
+     trunc_name(&slen, &sdots);
      a = inet_ntoa(rqst->rq_xprt->xp_raddr.sin_addr);
 
      proc = msg->rm_call.cb_proc;
@@ -1016,14 +1028,14 @@
      }
      if (procname != NULL)
 	  krb5_klog_syslog(LOG_NOTICE, "WARNING! Forged/garbled request: %s, "
-			   "claimed client = %s, server = %s, addr = %s",
-			   procname, client.value,
-			   server.value, a);
+			   "claimed client = %.*s%s, server = %.*s%s, addr = %s",
+			   procname, clen, client.value, cdots,
+			   slen, server.value, sdots, a);
      else
 	  krb5_klog_syslog(LOG_NOTICE, "WARNING! Forged/garbled request: %d, "
-			   "claimed client = %s, server = %s, addr = %s",
-			   proc, client.value,
-			   server.value, a);
+			   "claimed client = %.*s%s, server = %.*s%s, addr = %s",
+			   proc, clen, client.value, cdots,
+			   slen, server.value, sdots, a);
 
      (void) gss_release_buffer(&minor, &client);
      (void) gss_release_buffer(&minor, &server);
