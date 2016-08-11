--- src/zmath.c.orig	2003-01-17 00:49:06 UTC
+++ src/zmath.c
@@ -229,14 +229,10 @@ private int
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
