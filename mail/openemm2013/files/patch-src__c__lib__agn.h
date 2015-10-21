--- src/c/lib/agn.h.orig	2015-10-11 16:41:54 UTC
+++ src/c/lib/agn.h
@@ -135,9 +135,9 @@ typedef unsigned long	hash_t;
 /**
  * Symbolic names for boolean values
  */
-typedef enum { /*{{{*/
-	false,
-	true
+typedef enum { /*{{{*/ 
+	false = 0,
+	true = 1
 	/*}}}*/
 }	bool_t;
 
