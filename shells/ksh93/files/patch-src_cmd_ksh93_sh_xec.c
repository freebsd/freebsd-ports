--- src/cmd/ksh93/sh/xec.c.orig	2019-04-16 20:04:19 UTC
+++ src/cmd/ksh93/sh/xec.c
@@ -2167,7 +2167,7 @@ int sh_exec(Shell_t *shp, const Shnode_t *t, int flags
             }
 #ifdef timeofday
             times(&after);
-            timeofday(&ta);
+            timeofday(&tb);
             assert(tb.tv_sec);
             at = shp->gd->lim.clk_tck * (ta.tv_sec - tb.tv_sec);
             at += ((shp->gd->lim.clk_tck *
