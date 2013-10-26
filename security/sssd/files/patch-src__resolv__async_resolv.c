From 5434161320c86634512ac70e1d49c63375a71dc4 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 14/34] patch-src__resolv__async_resolv.c

---
 src/resolv/async_resolv.c | 3 ++-
 1 file changed, 2 insertions(+), 1 deletion(-)

diff --git src/resolv/async_resolv.c src/resolv/async_resolv.c
index 268d266..1bb84e5 100644
--- src/resolv/async_resolv.c
+++ src/resolv/async_resolv.c
@@ -1203,7 +1203,6 @@ resolv_is_address(const char *name)
     hints.ai_flags = AI_NUMERICHOST; /* No network lookups */
 
     ret = getaddrinfo(name, NULL, &hints, &res);
-    freeaddrinfo(res);
     if (ret != 0) {
         if (ret == -2) {
             DEBUG(9, ("[%s] does not look like an IP address\n", name));
@@ -1211,6 +1210,8 @@ resolv_is_address(const char *name)
             DEBUG(2, ("getaddrinfo failed [%d]: %s\n",
                       ret, gai_strerror(ret)));
         }
+    } else {
+     freeaddrinfo(res);
     }
 
     return ret == 0;
-- 
1.8.0

