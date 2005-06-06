--- lib/pr_warp_network.c.orig	Wed May 25 10:37:48 2005
+++ lib/pr_warp_network.c	Wed May 25 10:38:03 2005
@@ -142,7 +142,7 @@
     apr_status_t ret=APR_SUCCESS;
     apr_socket_t *sock=NULL;
 
-    ret=apr_socket_create(&sock,AF_INET,SOCK_STREAM,wa_pool);
+    ret=apr_socket_create(&sock,AF_INET,SOCK_STREAM,0,wa_pool);
     if (ret!=APR_SUCCESS) {
         sock=NULL;
         wa_log(WA_MARK,"Cannot create socket for conn. \"%s\"",conn->name);
