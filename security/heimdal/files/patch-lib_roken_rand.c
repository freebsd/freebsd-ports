--- lib/roken/rand.c.orig	2016-12-20 14:23:06 UTC
+++ lib/roken/rand.c
@@ -42,7 +42,6 @@ void ROKEN_LIB_FUNCTION
 rk_random_init(void)
 {
 #if defined(HAVE_ARC4RANDOM)
-    arc4random_stir();
 #elif defined(HAVE_SRANDOMDEV)
     srandomdev();
 #elif defined(HAVE_RANDOM)
