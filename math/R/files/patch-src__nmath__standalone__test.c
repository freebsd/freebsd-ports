--- src/nmath/standalone/test.c.orig	2012-04-15 22:05:35 UTC
+++ src/nmath/standalone/test.c
@@ -38,7 +38,7 @@ main(int argc, char** argv)
     qnorm(0.7, 0.0, 1.0, 0, 0);
     printf("*** loaded '%s'\n", argv[0]);
     set_seed(123, 456);
-    N01_kind = AHRENS_DIETER;
+    N01type N01_kind = AHRENS_DIETER;
     printf("one normal %f\n", norm_rand());
     set_seed(123, 456);
     N01_kind = BOX_MULLER;
