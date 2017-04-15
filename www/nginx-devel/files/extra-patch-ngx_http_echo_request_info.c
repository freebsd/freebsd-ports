--- ../echo-nginx-module-46334b3/src/ngx_http_echo_request_info.c.orig	2017-04-15 10:03:29.616243000 -0400
+++ ../echo-nginx-module-46334b3/src/ngx_http_echo_request_info.c	2017-04-15 10:07:41.329695000 -0400
@@ -179,6 +179,9 @@
     ngx_int_t                    i, j;
     ngx_buf_t                   *b, *first = NULL;
     unsigned                     found;
+#if defined(nginx_version) && nginx_version >= 1011011
+    ngx_chain_t                 *cl;
+#endif 
     ngx_connection_t            *c;
     ngx_http_request_t          *mr;
     ngx_http_connection_t       *hc;
@@ -215,8 +218,15 @@
 
     if (hc->nbusy) {
         b = NULL;
+
+#if defined(nginx_version) && nginx_version >= 1011011
+        for (cl = hc->busy; cl; /* void */) {
+            b = cl->buf;
+            cl = cl->next;
+#else
         for (i = 0; i < hc->nbusy; i++) {
             b = hc->busy[i];
+#endif
 
             if (first == NULL) {
                 if (mr->request_line.data >= b->pos
@@ -280,8 +290,14 @@
     }
 
     if (hc->nbusy) {
+#if defined(nginx_version) && nginx_version >= 1011011
+        for (cl = hc->busy; cl; /* void */) {
+            b = cl->buf;
+            cl = cl->next;
+#else
         for (i = 0; i < hc->nbusy; i++) {
             b = hc->busy[i];
+#endif
 
             if (!found) {
                 if (b != first) {
