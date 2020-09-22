--- alias.h.orig	2008-07-12 06:05:22 UTC
+++ alias.h
@@ -50,4 +50,4 @@
 #define alias_unset(n)		var_unset1(&alias_head, n)
 #define alias_lookup(n)		(*var_lookup1(&alias_head, n))
 
-struct var *alias_head;
+extern struct var *alias_head;
