--- ../ngx_dynamic_upstream-0.1.3/src/ngx_inet_slab.c.orig	2016-05-25 19:27:27.204200000 -0400
+++ ../ngx_dynamic_upstream-0.1.3/src/ngx_inet_slab.c	2016-05-25 19:28:07.177622000 -0400
@@ -250,7 +250,7 @@
             return NGX_ERROR;
         }
 
-        ngx_memcpy(sin, u->sockaddr, sizeof(struct sockaddr_in));
+        ngx_memcpy(sin, &u->sockaddr, sizeof(struct sockaddr_in));
 
         u->addrs[0].sockaddr = (struct sockaddr *) sin;
         u->addrs[0].socklen = sizeof(struct sockaddr_in);
@@ -277,7 +277,7 @@
 
     u->family = u->addrs[0].sockaddr->sa_family;
     u->socklen = u->addrs[0].socklen;
-    ngx_memcpy(u->sockaddr, u->addrs[0].sockaddr, u->addrs[0].socklen);
+    ngx_memcpy(&u->sockaddr, u->addrs[0].sockaddr, u->addrs[0].socklen);
 
     switch (u->family) {
 
@@ -405,7 +405,7 @@
         return NGX_ERROR;
     }
 
-    ngx_memcpy(sin6, u->sockaddr, sizeof(struct sockaddr_in6));
+    ngx_memcpy(sin6, &u->sockaddr, sizeof(struct sockaddr_in6));
 
     u->addrs[0].sockaddr = (struct sockaddr *) sin6;
     u->addrs[0].socklen = sizeof(struct sockaddr_in6);
