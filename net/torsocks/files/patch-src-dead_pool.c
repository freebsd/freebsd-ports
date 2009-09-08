--- src/dead_pool.c	2009-02-07 12:00:03.000000000 +0100
+++ src/dead_pool.c	2009-08-18 07:35:08.000000000 +0200
@@ -725,7 +721,7 @@
     /* TODO: work out what to do with AF_INET6 requests */
 
 #ifdef HAVE_INET_ATON
-    if(inet_aton(node, &addr) == 0) {
+    if(node && inet_aton(node, &addr) == 0 && memcmp(node,"*",1)) {
 #elif defined(HAVE_INET_ADDR)
     /* If we're stuck with inet_addr, then getaddrinfo() won't work 
        properly with 255.255.255.255 (= -1).  There's not much we can
