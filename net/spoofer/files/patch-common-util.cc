--- common/util.cc.orig	2019-02-28 19:32:23 UTC
+++ common/util.cc
@@ -180,10 +180,7 @@ void win_init(void) {
 void spoofer_rand_stir()
 {
 #if defined(HAVE_ARC4RANDOM)
- #if defined(__OpenBSD__) && !defined(HAVE_ARC4RANDOM_STIR)
-    // On OpenBSD 5.5+, the arc4random() function is not actually the ARC4
-    // algorithm, and there is no arc4random_stir() function.
- #else
+ #if defined(HAVE_ARC4RANDOM_STIR)
     arc4random_stir();
  #endif
 #elif defined(HAVE_SRANDOMDEV)
