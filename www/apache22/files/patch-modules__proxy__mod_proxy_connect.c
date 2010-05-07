--- ./modules/proxy/mod_proxy_connect.c.orig	2009-11-19 09:07:46.000000000 -0500
+++ ./modules/proxy/mod_proxy_connect.c	2010-05-06 19:37:54.227730259 -0400
@@ -21,6 +21,8 @@
 #include "mod_proxy.h"
 #include "apr_poll.h"
 
+#define CONN_BLKSZ AP_IOBUFSIZE
+
 module AP_MODULE_DECLARE_DATA proxy_connect_module;
 
 /*
@@ -71,6 +73,50 @@
     return OK;
 }
 
+/* read available data (in blocks of CONN_BLKSZ) from c_i and copy to c_o */
+static int proxy_connect_transfer(request_rec *r, conn_rec *c_i, conn_rec *c_o,
+				  apr_bucket_brigade *bb, char *name)
+{
+    int rv;
+#ifdef DEBUGGING
+    apr_off_t len;
+#endif
+
+    do {
+	apr_brigade_cleanup(bb);
+	rv = ap_get_brigade(c_i->input_filters, bb, AP_MODE_READBYTES,
+			    APR_NONBLOCK_READ, CONN_BLKSZ);
+	if (rv == APR_SUCCESS) {
+	    if (APR_BRIGADE_EMPTY(bb))
+		break;
+#ifdef DEBUGGING
+	    len = -1;
+	    apr_brigade_length(bb, 0, &len);
+	    ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r,
+			  "proxy: CONNECT: read %" APR_OFF_T_FMT
+			  " bytes from %s", len, name);
+#endif
+	    rv = ap_pass_brigade(c_o->output_filters, bb);
+	    if (rv == APR_SUCCESS) {
+		ap_fflush(c_o->output_filters, bb);
+	    } else {
+		ap_log_rerror(APLOG_MARK, APLOG_ERR, rv, r,
+			      "proxy: CONNECT: error on %s - ap_pass_brigade",
+			      name);
+	    }
+	} else if (!APR_STATUS_IS_EAGAIN(rv)) {
+	    ap_log_rerror(APLOG_MARK, APLOG_DEBUG, rv, r,
+			  "proxy: CONNECT: error on %s - ap_get_brigade",
+			  name);
+	}
+    } while (rv == APR_SUCCESS);
+
+    if (APR_STATUS_IS_EAGAIN(rv)) {
+	rv = APR_SUCCESS;
+    }
+    return rv;
+}
+
 /* CONNECT handler */
 static int proxy_connect_handler(request_rec *r, proxy_worker *worker,
                                  proxy_server_conf *conf,
@@ -79,11 +125,15 @@
 {
     apr_pool_t *p = r->pool;
     apr_socket_t *sock;
+    conn_rec *c = r->connection;
+    conn_rec *backconn;
+
+    apr_bucket_brigade *bb = apr_brigade_create(p, c->bucket_alloc);
     apr_status_t err, rv;
-    apr_size_t i, o, nbytes;
+    apr_size_t nbytes;
     char buffer[HUGE_STRING_LEN];
-    apr_socket_t *client_socket = ap_get_module_config(r->connection->conn_config, &core_module);
-    int failed;
+    apr_socket_t *client_socket = ap_get_module_config(c->conn_config, &core_module);
+    int failed, rc;
     apr_pollset_t *pollset;
     apr_pollfd_t pollfd;
     const apr_pollfd_t *signalled;
@@ -158,12 +208,10 @@
             case APR_URI_SNEWS_DEFAULT_PORT:
                 break;
             default:
-                /* XXX can we call ap_proxyerror() here to get a nice log message? */
-                return HTTP_FORBIDDEN;
+        return ap_proxyerror(r, HTTP_FORBIDDEN, "Connect to remote machine blocked");
         }
     } else if(!allowed_port(conf, uri.port)) {
-        /* XXX can we call ap_proxyerror() here to get a nice log message? */
-        return HTTP_FORBIDDEN;
+    return ap_proxyerror(r, HTTP_FORBIDDEN, "Connect to remote machine blocked");
     }
 
     /*
@@ -205,18 +253,57 @@
         }
     }
 
+    /* setup polling for connection */
+    ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r,
+		  "proxy: CONNECT: setting up poll()");
+
+    if ((rv = apr_pollset_create(&pollset, 2, r->pool, 0)) != APR_SUCCESS) {
+	apr_socket_close(sock);
+        ap_log_rerror(APLOG_MARK, APLOG_ERR, rv, r,
+            "proxy: CONNECT: error apr_pollset_create()");
+        return HTTP_INTERNAL_SERVER_ERROR;
+    }
+
+    /* Add client side to the poll */
+    pollfd.p = r->pool;
+    pollfd.desc_type = APR_POLL_SOCKET;
+    pollfd.reqevents = APR_POLLIN;
+    pollfd.desc.s = client_socket;
+    pollfd.client_data = NULL;
+    apr_pollset_add(pollset, &pollfd);
+
+    /* Add the server side to the poll */
+    pollfd.desc.s = sock;
+    apr_pollset_add(pollset, &pollfd);
+
     /*
      * Step Three: Send the Request
      *
      * Send the HTTP/1.1 CONNECT request to the remote server
      */
 
-    /* we are acting as a tunnel - the output filter stack should
-     * be completely empty, because when we are done here we are done completely.
-     * We add the NULL filter to the stack to do this...
-     */
-    r->output_filters = NULL;
-    r->connection->output_filters = NULL;
+    backconn = ap_run_create_connection(c->pool, r->server, sock,
+					c->id, c->sbh, c->bucket_alloc);
+    if (!backconn) {
+	/* peer reset */
+	ap_log_rerror(APLOG_MARK, APLOG_INFO, 0, r,
+		      "proxy: an error occurred creating a new connection "
+		      "to %pI (%s)", connect_addr, connectname);
+	apr_socket_close(sock);
+	return HTTP_INTERNAL_SERVER_ERROR;
+    }
+    ap_proxy_ssl_disable(backconn);
+    rc = ap_run_pre_connection(backconn, sock);
+    if (rc != OK && rc != DONE) {
+	backconn->aborted = 1;
+	ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r,
+		      "proxy: CONNECT: pre_connection setup failed (%d)", rc);
+	return HTTP_INTERNAL_SERVER_ERROR;
+    }
+
+    ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r,
+		  "proxy: CONNECT: connection complete to %pI (%s)",
+		  connect_addr, connectname);
 
 
     /* If we are connecting through a remote proxy, we need to pass
@@ -227,12 +314,11 @@
      */
         ap_log_error(APLOG_MARK, APLOG_DEBUG, 0, r->server,
              "proxy: CONNECT: sending the CONNECT request to the remote proxy");
-        nbytes = apr_snprintf(buffer, sizeof(buffer),
+	ap_fprintf(backconn->output_filters, bb,
                   "CONNECT %s HTTP/1.0" CRLF, r->uri);
-        apr_socket_send(sock, buffer, &nbytes);
-        nbytes = apr_snprintf(buffer, sizeof(buffer),
-                  "Proxy-agent: %s" CRLF CRLF, ap_get_server_banner());
-        apr_socket_send(sock, buffer, &nbytes);
+         ap_fprintf(backconn->output_filters, bb,
+                  "Proxy-agent: %s" CRLF CRLF, ap_get_server_version());
+         ap_fflush(backconn->output_filters, bb);
     }
     else {
         ap_log_error(APLOG_MARK, APLOG_DEBUG, 0, r->server,
@@ -240,11 +326,12 @@
         nbytes = apr_snprintf(buffer, sizeof(buffer),
                   "HTTP/1.0 200 Connection Established" CRLF);
         ap_xlate_proto_to_ascii(buffer, nbytes);
-        apr_socket_send(client_socket, buffer, &nbytes);
+       ap_fwrite(c->output_filters, bb, buffer, nbytes); 
         nbytes = apr_snprintf(buffer, sizeof(buffer),
                   "Proxy-agent: %s" CRLF CRLF, ap_get_server_banner());
         ap_xlate_proto_to_ascii(buffer, nbytes);
-        apr_socket_send(client_socket, buffer, &nbytes);
+        ap_fwrite(c->output_filters, bb, buffer, nbytes);
+	ap_fflush(c->output_filters, bb);
 #if 0
         /* This is safer code, but it doesn't work yet.  I'm leaving it
          * here so that I can fix it later.
@@ -265,27 +352,15 @@
      * Handle two way transfer of data over the socket (this is a tunnel).
      */
 
+    /* we are now acting as a tunnel - the input/output filter stacks should
+     * not contain any non-connection filters.
+     */
+    r->output_filters = c->output_filters;
+    r->proto_output_filters = c->output_filters;
+    r->input_filters = c->input_filters;
+    r->proto_input_filters = c->input_filters;
 /*    r->sent_bodyct = 1;*/
 
-    if ((rv = apr_pollset_create(&pollset, 2, r->pool, 0)) != APR_SUCCESS) {
-        apr_socket_close(sock);
-        ap_log_rerror(APLOG_MARK, APLOG_ERR, rv, r,
-            "proxy: CONNECT: error apr_pollset_create()");
-        return HTTP_INTERNAL_SERVER_ERROR;
-    }
-
-    /* Add client side to the poll */
-    pollfd.p = r->pool;
-    pollfd.desc_type = APR_POLL_SOCKET;
-    pollfd.reqevents = APR_POLLIN;
-    pollfd.desc.s = client_socket;
-    pollfd.client_data = NULL;
-    apr_pollset_add(pollset, &pollfd);
-
-    /* Add the server side to the poll */
-    pollfd.desc.s = sock;
-    apr_pollset_add(pollset, &pollfd);
-
     while (1) { /* Infinite loop until error (one side closes the connection) */
         if ((rv = apr_pollset_poll(pollset, -1, &pollcnt, &signalled)) != APR_SUCCESS) {
             apr_socket_close(sock);
@@ -294,7 +369,7 @@
         }
 #ifdef DEBUGGING
         ap_log_error(APLOG_MARK, APLOG_DEBUG, 0, r->server,
-                     "proxy: CONNECT: woke from select(), i=%d", pollcnt);
+                     "proxy: CONNECT: woke from poll(), i=%d", pollcnt);
 #endif
 
         for (pi = 0; pi < pollcnt; pi++) {
@@ -304,72 +379,32 @@
                 pollevent = cur->rtnevents;
                 if (pollevent & APR_POLLIN) {
 #ifdef DEBUGGING
-                    ap_log_error(APLOG_MARK, APLOG_DEBUG, 0, r->server,
-                                 "proxy: CONNECT: sock was set");
+                    ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r,
+                                 "proxy: CONNECT: sock was readable");
 #endif
-                    nbytes = sizeof(buffer);
-                    rv = apr_socket_recv(sock, buffer, &nbytes);
-                    if (rv == APR_SUCCESS) {
-                        o = 0;
-                        i = nbytes;
-                        while(i > 0)
-                        {
-                            nbytes = i;
-    /* This is just plain wrong.  No module should ever write directly
-     * to the client.  For now, this works, but this is high on my list of
-     * things to fix.  The correct line is:
-     * if ((nbytes = ap_rwrite(buffer + o, nbytes, r)) < 0)
-     * rbb
-     */
-                            rv = apr_socket_send(client_socket, buffer + o, &nbytes);
-                            if (rv != APR_SUCCESS)
-                                break;
-                            o += nbytes;
-                            i -= nbytes;
-                        }
+                    rv = proxy_connect_transfer(r, backconn, c, bb, "sock");
                     }
-                    else
-                        break;
+                else if ((pollevent & APR_POLLERR) || (pollevent & APR_POLLHUP)) {
+		    rv = APR_EPIPE;
+                    ap_log_rerror(APLOG_MARK, APLOG_NOTICE, 0, r, "proxy: CONNECT: err/hup on backconn");
                 }
-                else if ((pollevent & APR_POLLERR) || (pollevent & APR_POLLHUP))
-                    break;
             }
             else if (cur->desc.s == client_socket) {
                 pollevent = cur->rtnevents;
                 if (pollevent & APR_POLLIN) {
 #ifdef DEBUGGING
-                    ap_log_error(APLOG_MARK, APLOG_DEBUG, 0, r->server,
-                                 "proxy: CONNECT: client was set");
-#endif
-                    nbytes = sizeof(buffer);
-                    rv = apr_socket_recv(client_socket, buffer, &nbytes);
-                    if (rv == APR_SUCCESS) {
-                        o = 0;
-                        i = nbytes;
-#ifdef DEBUGGING
-                        ap_log_error(APLOG_MARK, APLOG_DEBUG, 0, r->server,
-                                     "proxy: CONNECT: read %d from client", i);
+                    ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r,
+                                 "proxy: CONNECT: client was readable");
 #endif
-                        while(i > 0)
-                        {
-                            nbytes = i;
-                            rv = apr_socket_send(sock, buffer + o, &nbytes);
-                            if (rv != APR_SUCCESS)
-                                break;
-                            o += nbytes;
-                            i -= nbytes;
-                        }
-                    }
-                    else
-                        break;
+                    rv = proxy_connect_transfer(r, c, backconn, bb, "client");
                 }
-                else if ((pollevent & APR_POLLERR) || (pollevent & APR_POLLHUP)) {
-                    rv = APR_EOF;
-                    break;
                 }
+            else {
+                rv = APR_EBADF;
+                ap_log_rerror(APLOG_MARK, APLOG_INFO, 0, r,
+			      "proxy: CONNECT: unknown socket in pollset");
             }
-            else
-                break;
+               
         }
         if (rv != APR_SUCCESS) {
             break;
@@ -385,7 +420,9 @@
      * Close the socket and clean up
      */
 
-    apr_socket_close(sock);
+    ap_lingering_close(backconn);
+
+    c->aborted = 1;
 
     return OK;
 }
