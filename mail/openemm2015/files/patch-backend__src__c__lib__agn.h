--- backend/src/c/lib/agn.h.orig	2015-10-24 14:59:57 UTC
+++ backend/src/c/lib/agn.h
@@ -136,8 +136,8 @@ typedef unsigned long	hash_t;
  * Symbolic names for boolean values
  */
 typedef enum { /*{{{*/
-	false,
-	true
+	false = 0,
+	true = 1
 	/*}}}*/
 }	bool_t;
 
