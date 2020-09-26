--- source4/heimdal/lib/roken/rand.c.orig	2019-01-15 10:07:00 UTC
+++ source4/heimdal/lib/roken/rand.c
@@ -37,7 +37,6 @@ void ROKEN_LIB_FUNCTION
 rk_random_init(void)
 {
 #if defined(HAVE_ARC4RANDOM)
-    arc4random_stir();
 #elif defined(HAVE_SRANDOMDEV)
     srandomdev();
 #elif defined(HAVE_RANDOM)
