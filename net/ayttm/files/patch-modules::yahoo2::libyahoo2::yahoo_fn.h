--- modules/yahoo2/libyahoo2/yahoo_fn.h.orig	Thu Jan 15 08:01:45 2004
+++ modules/yahoo2/libyahoo2/yahoo_fn.h	Sun Feb  8 01:03:04 2004
@@ -27,7 +27,11 @@
 struct yahoo_fn
 {
 	int type; /* type of transform */
-	int arg1, arg2; /* arguments */
+	union {
+		unsigned char *table;
+		int arg1;
+	      } arg1_u;
+	int arg2; /* arguments */
 };
 
 int yahoo_xfrm( int table, int depth, int seed );
