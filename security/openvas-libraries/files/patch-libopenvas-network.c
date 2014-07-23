--- libopenvas/network.c.orig
+++ libopenvas/network.c
@@ -771,8 +771,6 @@
     }
 
   unblock_socket(fp->fd);
-  /* for non-blocking sockets, gnutls requires a 0 lowat value */
-  gnutls_transport_set_lowat(fp->tls_session, 0);
 
   gnutls_transport_set_ptr(fp->tls_session, (gnutls_transport_ptr_t) GSIZE_TO_POINTER(fp->fd));
 
