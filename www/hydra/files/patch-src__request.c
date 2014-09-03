--- src/request.c.orig
+++ src/request.c
@@ -133,7 +133,7 @@
    int len;
    static int sockbufsize = SOCKETBUF_SIZE;
 #ifdef ENABLE_SSL
-   gnutls_session ssl_state = NULL;
+   gnutls_session_t ssl_state = NULL;
 #endif
 
    remote_addr.S_FAMILY = 0xdead;
@@ -194,7 +194,7 @@
 	 return;
       }
 
-      gnutls_transport_set_ptr(ssl_state, (gnutls_transport_ptr)fd);
+      gnutls_transport_set_ptr(ssl_state, (gnutls_transport_ptr_t)fd);
    }
 #endif
 
