--- ./src/lib/valuepair.c.orig	2014-03-29 10:01:05.000000000 -0400
+++ ./src/lib/valuepair.c	2014-03-29 10:01:14.000000000 -0400
@@ -2331,7 +2331,7 @@
  */
 int paircmp_op(VALUE_PAIR const *one, FR_TOKEN op, VALUE_PAIR const *two)
 {
-	int compare;
+	int compare = 0;
 
 	VERIFY_VP(one);
 	VERIFY_VP(two);
