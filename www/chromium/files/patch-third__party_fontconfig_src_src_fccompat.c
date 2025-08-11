--- third_party/fontconfig/src/src/fccompat.c.orig	2025-07-02 06:08:04 UTC
+++ third_party/fontconfig/src/src/fccompat.c
@@ -175,7 +175,9 @@ FcRandom (void)
 {
     int32_t result;
 
-#if HAVE_RANDOM_R
+#if HAVE_ARC4RANDOM
+    result = arc4random() & 0x7fffffff;
+#elif HAVE_RANDOM_R
     static struct random_data fcrandbuf;
     static char               statebuf[256];
     static FcBool             initialized = FcFalse;
