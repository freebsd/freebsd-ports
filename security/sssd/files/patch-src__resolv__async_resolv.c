--- ./src/resolv/async_resolv.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/resolv/async_resolv.c	2011-10-13 12:15:03.000000000 -0400
@@ -1073,7 +1073,6 @@
     hints.ai_flags = AI_NUMERICHOST; /* No network lookups */
 
     ret = getaddrinfo(name, NULL, &hints, &res);
-    freeaddrinfo(res);
     if (ret != 0) {
         if (ret == -2) {
             DEBUG(9, ("[%s] does not look like an IP address\n", name));
@@ -1081,6 +1080,8 @@
             DEBUG(2, ("getaddrinfo failed [%d]: %s\n",
                       ret, gai_strerror(ret)));
         }
+    } else {
+     freeaddrinfo(res);
     }
 
     return ret == 0;
