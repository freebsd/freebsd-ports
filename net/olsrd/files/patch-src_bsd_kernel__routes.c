--- src/bsd/kernel_routes.c.orig	2019-08-11 08:09:47 UTC
+++ src/bsd/kernel_routes.c
@@ -351,7 +351,9 @@ add_del_route6(const struct rt_entry *rt, int add)
     memcpy(walker, &sdl, sizeof(sdl));
     walker += sdl_size;
     rtm->rtm_addrs |= RTA_GATEWAY;
+#ifdef RTF_CLONING
     rtm->rtm_flags |= RTF_CLONING;
+#endif /* RTF_CLONING */
     rtm->rtm_flags &= ~RTF_GATEWAY;
   }
 
