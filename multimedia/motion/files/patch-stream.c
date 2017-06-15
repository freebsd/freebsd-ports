--- stream.c.orig	2016-10-25 01:39:24 UTC
+++ stream.c
@@ -727,9 +727,9 @@ int http_bindsock(int port, int local, i
     const char *addr_str;
     struct sockaddr_storage sin;
     bzero(&sin, sizeof(struct sockaddr_storage));
-    sin.ss_family = ipv6_enabled?AF_INET6:AF_INET;
     if (ipv6_enabled) {
         struct sockaddr_in6 *sin6 = (struct sockaddr_in6*)&sin;
+        sin6->sin6_len = sizeof(struct sockaddr_in6);
         sin6->sin6_family = AF_INET6;
         sin6->sin6_port = htons(port);
         if(local) {
@@ -741,6 +741,7 @@ int http_bindsock(int port, int local, i
         }
     } else {
         struct sockaddr_in *sin4 = (struct sockaddr_in*)&sin;
+        sin4->sin_len = sizeof(struct sockaddr_in);
         sin4->sin_family = AF_INET;
         sin4->sin_port = htons(port);
         if(local) {
@@ -752,8 +753,8 @@ int http_bindsock(int port, int local, i
         }
     }
 
-    if (bind(sd, (struct sockaddr*)&sin, sizeof(sin)) != 0) {
-        MOTION_LOG(NTC, TYPE_STREAM, NO_ERRNO, "%s: error binding on %s port %d", addr_str, port);
+    if (bind(sd, (struct sockaddr*)&sin, sin.ss_len) != 0) {
+        MOTION_LOG(NTC, TYPE_STREAM, SHOW_ERRNO, "%s: error binding on %s port %d", addr_str, port);
         close(sd);
         return -1;
     }
