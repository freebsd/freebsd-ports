--- ./support/ab.c.orig	2010-01-07 10:11:53.000000000 -0500
+++ ./support/ab.c	2010-05-06 19:37:54.262732305 -0400
@@ -221,13 +221,18 @@
 /* maximum number of requests on a time limited test */
 #define MAX_REQUESTS (INT_MAX > 50000 ? 50000 : INT_MAX)
 
-/* good old state hostname */
-#define STATE_UNCONNECTED 0
-#define STATE_CONNECTING  1     /* TCP connect initiated, but we don't
+/* connection state
+ * don't add enums or rearrange or otherwise change values without
+ * visiting set_conn_state()
+ */
+typedef enum {
+    STATE_UNCONNECTED = 0,
+    STATE_CONNECTING,           /* TCP connect initiated, but we don't
                                  * know if it worked yet
                                  */
-#define STATE_CONNECTED   2     /* we know TCP connect completed */
-#define STATE_READ        3
+    STATE_CONNECTED,            /* we know TCP connect completed */
+    STATE_READ
+} connect_state_e;
 
 #define CBUFFSIZE (2048)
 
@@ -252,6 +257,7 @@
                done;            /* Connection closed */
 
     int socknum;
+    apr_int16_t reqevents;      /* current poll events for this socket */
 #ifdef USE_SSL
     SSL *ssl;
 #endif
@@ -396,6 +402,56 @@
     exit(rv);
 }
 
+static void set_polled_events(struct connection *c, apr_int16_t new_reqevents)
+{
+    apr_int16_t old_reqevents = c->reqevents;
+    apr_pollfd_t pfd;
+    apr_status_t rv;
+    char buf[120];
+
+    if (old_reqevents != new_reqevents) {
+        pfd.desc_type = APR_POLL_SOCKET;
+        pfd.desc.s = c->aprsock;
+        pfd.client_data = c;
+
+        if (old_reqevents != 0) {
+            pfd.reqevents = old_reqevents;
+            rv = apr_pollset_remove(readbits, &pfd);
+            if (rv != APR_SUCCESS) {
+                apr_err("apr_pollset_remove()", rv);
+            }
+        }
+
+        if (new_reqevents != 0) {
+            pfd.reqevents = new_reqevents;
+            rv = apr_pollset_add(readbits, &pfd);
+            if (rv != APR_SUCCESS) {
+                apr_err("apr_pollset_add()", rv);
+                exit(1);
+            }
+        }
+
+        c->reqevents = new_reqevents;
+    }
+}
+
+static void set_conn_state(struct connection *c, connect_state_e new_state)
+{
+    apr_int16_t events_by_state[] = {
+        0,           /* for STATE_UNCONNECTED */
+        APR_POLLOUT, /* for STATE_CONNECTING */
+        APR_POLLIN,  /* for STATE_CONNECTED; we don't poll in this state,
+                      * so prepare for polling in the following state --
+                      * STATE_READ
+                      */
+        APR_POLLIN   /* for STATE_READ */
+    };
+
+    c->state = new_state;
+
+    set_polled_events(c, events_by_state[new_state]);
+}
+
 /* --------------------------------------------------------- */
 /* write out request to a connection - assumes we can write
  * (small) request out in one go into our new socket buffer
@@ -569,7 +625,6 @@
 
     while (do_next) {
         int ret, ecode;
-        apr_pollfd_t new_pollfd;
 
         ret = SSL_do_handshake(c->ssl);
         ecode = SSL_get_error(c->ssl, ret);
@@ -601,11 +656,7 @@
             do_next = 0;
             break;
         case SSL_ERROR_WANT_READ:
-            new_pollfd.desc_type = APR_POLL_SOCKET;
-            new_pollfd.reqevents = APR_POLLIN;
-            new_pollfd.desc.s = c->aprsock;
-            new_pollfd.client_data = c;
-            apr_pollset_add(readbits, &new_pollfd);
+            set_polled_events(c, APR_POLLIN);
             do_next = 0;
             break;
         case SSL_ERROR_WANT_WRITE:
@@ -681,16 +732,8 @@
         c->rwrite -= l;
     } while (c->rwrite);
 
-    c->state = STATE_READ;
     c->endwrite = lasttime = apr_time_now();
-    {
-        apr_pollfd_t new_pollfd;
-        new_pollfd.desc_type = APR_POLL_SOCKET;
-        new_pollfd.reqevents = APR_POLLIN;
-        new_pollfd.desc.s = c->aprsock;
-        new_pollfd.client_data = c;
-        apr_pollset_add(readbits, &new_pollfd);
-    }
+    set_conn_state(c, STATE_READ);
 }
 
 /* --------------------------------------------------------- */
@@ -1210,21 +1253,12 @@
 #endif
     if ((rv = apr_socket_connect(c->aprsock, destsa)) != APR_SUCCESS) {
         if (APR_STATUS_IS_EINPROGRESS(rv)) {
-            apr_pollfd_t new_pollfd;
-            c->state = STATE_CONNECTING;
+            set_conn_state(c, STATE_CONNECTING);
             c->rwrite = 0;
-            new_pollfd.desc_type = APR_POLL_SOCKET;
-            new_pollfd.reqevents = APR_POLLOUT;
-            new_pollfd.desc.s = c->aprsock;
-            new_pollfd.client_data = c;
-            apr_pollset_add(readbits, &new_pollfd);
             return;
         }
         else {
-            apr_pollfd_t remove_pollfd;
-            remove_pollfd.desc_type = APR_POLL_SOCKET;
-            remove_pollfd.desc.s = c->aprsock;
-            apr_pollset_remove(readbits, &remove_pollfd);
+            set_conn_state(c, STATE_UNCONNECTED);
             apr_socket_close(c->aprsock);
             err_conn++;
             if (bad++ > 10) {
@@ -1232,14 +1266,14 @@
                    "\nTest aborted after 10 failures\n\n");
                 apr_err("apr_socket_connect()", rv);
             }
-            c->state = STATE_UNCONNECTED;
+            
             start_connect(c);
             return;
         }
     }
 
     /* connected first time */
-    c->state = STATE_CONNECTED;
+    set_conn_state(c, STATE_CONNECTED); /* will this waste a pollset call? */
     started++;
 #ifdef USE_SSL
     if (c->ssl) {
@@ -1288,21 +1322,15 @@
         }
     }
 
-    {
-        apr_pollfd_t remove_pollfd;
-        remove_pollfd.desc_type = APR_POLL_SOCKET;
-        remove_pollfd.desc.s = c->aprsock;
-        apr_pollset_remove(readbits, &remove_pollfd);
+    set_conn_state(c, STATE_UNCONNECTED);
 #ifdef USE_SSL
-        if (c->ssl) {
-            SSL_shutdown(c->ssl);
-            SSL_free(c->ssl);
-            c->ssl = NULL;
-        }
-#endif
-        apr_socket_close(c->aprsock);
+    if (c->ssl) {
+        SSL_shutdown(c->ssl);
+        SSL_free(c->ssl);
+        c->ssl = NULL;
     }
-    c->state = STATE_UNCONNECTED;
+#endif
+    apr_socket_close(c->aprsock);
 
     /* connect again */
     start_connect(c);
@@ -1420,10 +1448,7 @@
             }
             else {
             /* header is in invalid or too big - close connection */
-                apr_pollfd_t remove_pollfd;
-                remove_pollfd.desc_type = APR_POLL_SOCKET;
-                remove_pollfd.desc.s = c->aprsock;
-                apr_pollset_remove(readbits, &remove_pollfd);
+                set_conn_state(c, STATE_UNCONNECTED);
                 apr_socket_close(c->aprsock);
                 err_response++;
                 if (bad++ > 10) {
@@ -1748,11 +1773,7 @@
             }
             if (rv & APR_POLLOUT) {
                 if (c->state == STATE_CONNECTING) {
-                    apr_pollfd_t remove_pollfd;
                     rv = apr_socket_connect(c->aprsock, destsa);
-                    remove_pollfd.desc_type = APR_POLL_SOCKET;
-                    remove_pollfd.desc.s = c->aprsock;
-                    apr_pollset_remove(readbits, &remove_pollfd);
                     if (rv != APR_SUCCESS) {
                         apr_socket_close(c->aprsock);
                         err_conn++;
@@ -1761,12 +1782,12 @@
                                     "\nTest aborted after 10 failures\n\n");
                             apr_err("apr_socket_connect()", rv);
                         }
-                        c->state = STATE_UNCONNECTED;
+                        set_conn_state(c, STATE_UNCONNECTED);
                         start_connect(c);
                         continue;
                     }
                     else {
-                        c->state = STATE_CONNECTED;
+                        set_conn_state(c, STATE_CONNECTED);
                         started++;
 #ifdef USE_SSL
                         if (c->ssl)
@@ -1780,22 +1801,6 @@
                     write_request(c);
                 }
             }
-
-            /*
-             * When using a select based poll every time we check the bits
-             * are reset. In 1.3's ab we copied the FD_SET's each time
-             * through, but here we're going to check the state and if the
-             * connection is in STATE_READ or STATE_CONNECTING we'll add the
-             * socket back in as APR_POLLIN.
-             */
-                if (c->state == STATE_READ) {
-                    apr_pollfd_t new_pollfd;
-                    new_pollfd.desc_type = APR_POLL_SOCKET;
-                    new_pollfd.reqevents = APR_POLLIN;
-                    new_pollfd.desc.s = c->aprsock;
-                    new_pollfd.client_data = c;
-                    apr_pollset_add(readbits, &new_pollfd);
-                }
         }
     } while (lasttime < stoptime && done < requests);
     
