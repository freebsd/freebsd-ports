--- ../nginx-rtmp-module-1.1.7/ngx_rtmp_core_module.c.orig	2016-05-25 19:25:35.779720000 -0400
+++ ../nginx-rtmp-module-1.1.7/ngx_rtmp_core_module.c	2016-05-25 19:26:28.055352000 -0400
@@ -545,7 +545,7 @@
             break;
         }
 
-        if (ngx_memcmp(ls[i].sockaddr + off, u.sockaddr + off, len) != 0) {
+        if (ngx_memcmp(ls[i].sockaddr + off, &u.sockaddr + off, len) != 0) {
             continue;
         }
 
@@ -565,7 +565,7 @@
 
     ngx_memzero(ls, sizeof(ngx_rtmp_listen_t));
 
-    ngx_memcpy(ls->sockaddr, u.sockaddr, u.socklen);
+    ngx_memcpy(ls->sockaddr, &u.sockaddr, u.socklen);
 
     ls->socklen = u.socklen;
     ls->wildcard = u.wildcard;
