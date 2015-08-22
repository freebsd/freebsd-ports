--- src/zmath.c.orig	2013-04-30 10:43:55.000000000 +0900
+++ src/zmath.c	2013-04-30 10:44:23.000000000 +0900
@@ -229,14 +229,10 @@
 zsrand(i_ctx_t *i_ctx_p)
 {
     os_ptr op = osp;
-    long state;
+    int state;
 
     check_type(*op, t_integer);
     state = op->value.intval;
-#if arch_sizeof_long > 4
-    /* Trim the state back to 32 bits. */
-    state = (int)state;
-#endif
     /*
      * The following somewhat bizarre adjustments are according to
      * public information from Adobe describing their implementation.
