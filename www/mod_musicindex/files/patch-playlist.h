--- playlist.h.orig	Thu Oct 30 20:41:45 2003
+++ playlist.h	Tue Nov  4 00:03:01 2003
@@ -51,5 +51,7 @@
 	
 mu_ent *new_ent(apr_pool_t *pool, mu_ent *head);
 
+#define FALSE 0
+#define TRUE !FALSE
 
 #endif
