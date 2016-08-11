--- src/zarith.c.orig	2003-01-17 00:49:05 UTC
+++ src/zarith.c
@@ -32,9 +32,9 @@
  */
 
 /* Define max and min values for what will fit in value.intval. */
-#define MIN_INTVAL min_long
-#define MAX_INTVAL max_long
-#define MAX_HALF_INTVAL ((1L << (size_of(long) * 4 - 1)) - 1)
+#define MIN_INTVAL 0x80000000
+#define MAX_INTVAL 0x7fffffff
+#define MAX_HALF_INTVAL 0x7fff
 
 /* <num1> <num2> add <sum> */
 /* We make this into a separate procedure because */
@@ -64,7 +64,7 @@ zop_add(register os_ptr op)
 	    op[-1].value.realval += (double)op->value.intval;
 	    break;
 	case t_integer: {
-	    long int2 = op->value.intval;
+	    int int2 = op->value.intval;
 
 	    if (((op[-1].value.intval += int2) ^ int2) < 0 &&
 		((op[-1].value.intval - int2) ^ int2) >= 0
@@ -158,10 +158,10 @@ zmul(i_ctx_t *i_ctx_p)
 	    op[-1].value.realval *= (double)op->value.intval;
 	    break;
 	case t_integer: {
-	    long int1 = op[-1].value.intval;
-	    long int2 = op->value.intval;
-	    long abs1 = (int1 >= 0 ? int1 : -int1);
-	    long abs2 = (int2 >= 0 ? int2 : -int2);
+	    int int1 = op[-1].value.intval;
+	    int int2 = op->value.intval;
+	    uint abs1 = (uint)(int1 >= 0 ? int1 : -int1);
+	    uint abs2 = (uint)(int2 >= 0 ? int2 : -int2);
 	    float fprod;
 
 	    if ((abs1 > MAX_HALF_INTVAL || abs2 > MAX_HALF_INTVAL) &&
@@ -212,7 +212,7 @@ zop_sub(register os_ptr op)
 	    op[-1].value.realval -= (double)op->value.intval;
 	    break;
 	case t_integer: {
-	    long int1 = op[-1].value.intval;
+	    int int1 = op[-1].value.intval;
 
 	    if ((int1 ^ (op[-1].value.intval = int1 - op->value.intval)) < 0 &&
 		(int1 ^ op->value.intval) < 0
