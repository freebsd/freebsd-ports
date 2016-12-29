--- lib/http2/connection.c.orig	2016-09-13 06:57:03 UTC
+++ lib/http2/connection.c
@@ -1329,6 +1329,7 @@ int h2o_http2_handle_upgrade(h2o_req_t *
 
     return 0;
 Error:
+    h2o_linklist_unlink(&http2conn->_conns);
     free(http2conn);
     return -1;
 }
