--- libhb/nlmeans.c.orig	2022-12-28 17:43:46.000000000 +0900
+++ libhb/nlmeans.c	2022-12-30 17:08:30.322878000 +0900
@@ -241,7 +241,7 @@
             pv->nlmeans_prefilter     = nlmeans_prefilter_8;
             pv->nlmeans_deborder      = nlmeans_deborder_8;
             pv->nlmeans_plane         = nlmeans_plane_8;
-        #if defined(ARCH_X86)
+        #if defined(ARCH_X86_64)
             nlmeans_init_x86(functions);
         #endif
             break;
