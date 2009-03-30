--- src/bsd/kernel_routes.c.orig	2009-03-17 23:52:47.000000000 +0200
+++ src/bsd/kernel_routes.c	2009-03-21 19:45:54.000000000 +0200
@@ -176,7 +176,9 @@
       memcpy(walker, sdl, sdl->sdl_len);
       walker += sdl_size;
       rtm->rtm_addrs |= RTA_GATEWAY;
+#ifdef RTF_CLONING
       rtm->rtm_flags |= RTF_CLONING;
+#endif
 #ifndef _WRS_KERNEL
       rtm->rtm_flags &= ~RTF_HOST;
 #endif
@@ -295,7 +297,7 @@
 #endif
     memcpy(walker, &sin6, sizeof(sin6));
     walker += sin_size;
-    rtm->rtm_addrs = RTA_GATEWAY;
+    rtm->rtm_addrs |= RTA_GATEWAY;
   }
   else {
     /*
@@ -313,7 +315,7 @@
 #endif
     memcpy(walker, &sin6, sizeof(sin6));
     walker += sin_size;
-    rtm->rtm_addrs = RTA_GATEWAY;
+    rtm->rtm_addrs |= RTA_GATEWAY;
     rtm->rtm_flags |= RTF_GATEWAY;
   }
 
