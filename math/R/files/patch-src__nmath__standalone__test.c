--- src/nmath/standalone/test.c.orig	2009-06-22 18:12:00.000000000 -0400
+++ src/nmath/standalone/test.c	2009-06-22 18:12:34.000000000 -0400
@@ -38,7 +38,7 @@
     qnorm(0.7, 0.0, 1.0, 0, 0);
     printf("*** loaded '%s'\n", argv[0]);
     set_seed(123, 456);
-    N01_kind = AHRENS_DIETER;
+    N01type N01_kind = AHRENS_DIETER;
     printf("one normal %f\n", norm_rand());
     set_seed(123, 456);
     N01_kind = BOX_MULLER;
