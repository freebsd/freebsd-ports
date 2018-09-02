--- source4/heimdal/lib/roken/rand.c.orig	2018-01-14 04:41:58 UTC
+++ source4/heimdal/lib/roken/rand.c
@@ -37,7 +37,6 @@
 rk_random_init(void)
 {
 #if defined(HAVE_ARC4RANDOM)
-    arc4random_stir();
 #elif defined(HAVE_SRANDOMDEV)
     srandomdev();
 #elif defined(HAVE_RANDOM)
