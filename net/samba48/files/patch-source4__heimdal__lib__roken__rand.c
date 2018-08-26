--- source4/heimdal/lib/roken/rand.c.orig	2018-01-14 12:41:58.000000000 -0800
+++ source4/heimdal/lib/roken/rand.c	2018-08-22 22:11:26.937151714 -0700
@@ -37,7 +37,6 @@
 rk_random_init(void)
 {
 #if defined(HAVE_ARC4RANDOM)
-    arc4random_stir();
 #elif defined(HAVE_SRANDOMDEV)
     srandomdev();
 #elif defined(HAVE_RANDOM)
