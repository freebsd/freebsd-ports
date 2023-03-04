--- src/imt_plugin.h.orig	2022-12-31 19:17:17 UTC
+++ src/imt_plugin.h
@@ -129,7 +129,7 @@ extern int compare_accounting_structure(struct acc *, 
 extern struct acc *search_accounting_structure(struct primitives_ptrs *);
 extern int compare_accounting_structure(struct acc *, struct primitives_ptrs *);
 
-extern void init_memory_pool_table();
+extern void init_memory_pool_table(struct configuration);
 extern void clear_memory_pool_table();
 extern struct memory_pool_desc *request_memory_pool(int);
 
