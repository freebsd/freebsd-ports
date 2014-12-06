--- conf/cf-lex.l.orig	2014-12-06 17:10:24.000000000 +0300
+++ conf/cf-lex.l	2014-12-06 17:10:41.000000000 +0300
@@ -61,7 +61,7 @@
 static int kw_hash_inited;
 
 #define SYM_HASH_SIZE 128
-#define SYM_MAX_LEN 32
+#define SYM_MAX_LEN 64
 
 struct sym_scope {
   struct sym_scope *next;		/* Next on scope stack */
