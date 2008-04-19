#
# Fix FD leak to PHP4 (from pecl-APC CVS)
#
--- apc_main.c	2008/03/29 06:38:40	3.103.2.3
+++ apc_main.c	2008/03/31 14:14:12	3.103.2.4
@@ -279,7 +279,11 @@
     apc_cache_release(apc_cache, cache_entry);
 
     /* cannot free up cache data yet, it maybe in use */
-    
+   
+#ifndef ZEND_ENGINE_2 
+    zend_llist_del_element(&CG(open_files), h, compare_file_handles); /* We leak fds in PHP 4 without this hack */
+#endif 
+
     h->type = ZEND_HANDLE_FILENAME;
 
     return NULL;
@@ -351,6 +355,11 @@
             reset_opened_path = 1;
         }
         zend_hash_add(&EG(included_files), h->opened_path, strlen(h->opened_path)+1, (void *)&dummy, sizeof(int), NULL);
+
+#ifndef ZEND_ENGINE_2 
+        zend_llist_add_element(&CG(open_files), h); /* We leak fds in PHP 4 without this hack */
+#endif
+
         apc_stack_push(APCG(cache_stack), cache_entry);
         op_array = cached_compile(h, type TSRMLS_CC);
         if(op_array) {
