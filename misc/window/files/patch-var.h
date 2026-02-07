--- var.h.orig	2008-07-12 06:05:22 UTC
+++ var.h
@@ -56,4 +56,4 @@ struct var **var_lookup1();
 #define var_lookup(n)		(*var_lookup1(&var_head, n))
 #define var_walk(f, a)		var_walk1(var_head, f, a)
 
-struct var *var_head;		/* secret, shhh */
+extern struct var *var_head;	/* secret, shhh */
