--- libyahoo/yahoo_fn.h	Fri May 28 03:56:54 2004
+++ libyahoo/yahoo_fn.h	Mon Aug  9 06:17:59 2004
@@ -26,8 +26,8 @@
 
 struct yahoo_fn
 {
-	int type; /* type of transform */
-	int arg1, arg2; /* arguments */
+	int type; 
+	long arg1, arg2;
 };
 
 int yahoo_xfrm( int table, int depth, int seed );
