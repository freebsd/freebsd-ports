--- eaccelerator.c.orig	Sun Nov 20 18:53:43 2005
+++ eaccelerator.c	Thu Feb  2 09:40:00 2006
@@ -110,6 +110,10 @@ extern dtor_func_t properties_info_dtor;
 /* saved original functions */
 static zend_op_array *(*mm_saved_zend_compile_file)(zend_file_handle *file_handle, int type TSRMLS_DC);
 
+#ifdef DEBUG
+static void (*mm_saved_zend_execute)(zend_op_array *op_array TSRMLS_DC);
+#endif
+
 /* external declarations */
 PHPAPI void php_stripslashes(char *str, int *len TSRMLS_DC);
 
@@ -251,16 +255,16 @@ static void hash_add_mm(mm_cache_entry *
 /* check the cache dir */
 static int check_cache_dir(char *cache_dir) {
   struct stat buf;
-  int uid = 0;
-  int gid = 0;
-
+//  int uid = 0;
+//  int gid = 0;
+  
   if (stat(cache_dir, &buf) == -1) {
     ea_debug_error("Cache dir does not exist (could not stat %s)\n", cache_dir);
-    return 0;
+    return FAILURE;
   }
   if (!(buf.st_mode & S_IFDIR)) {
     ea_debug_error("%s is not a directory!\n", cache_dir);
-    return 0;
+    return FAILURE;
   }
 #if 0
   uid = getuid();
@@ -272,7 +276,7 @@ static int check_cache_dir(char *cache_d
     return 0;
   }
 #endif
-  return 1;
+  return SUCCESS;
 }
 
 /* Initialise the shared memory */
@@ -326,11 +330,6 @@ static int init_mm(TSRMLS_D) {
   eaccelerator_mm_instance->user_hash_cnt = 0;
   eaccelerator_mm_instance->last_prune = time(0);
   EACCELERATOR_PROTECT();
-
-  if (!check_cache_dir(EAG(cache_dir))) {
-    return FAILURE;
-  }
-  
   return SUCCESS;
 }
 
@@ -847,7 +846,7 @@ static mm_cache_entry *eaccelerator_stor
   q = p->c_head;
   while (q != NULL) {
 #ifdef ZEND_ENGINE_2
-      q->fc = store_class_entry ((zend_class_entry *) q->fc TSRMLS_CC);
+      q->fc = store_class_entry ((zend_class_entry *) q->fc TSRMLS_CC);  // hra: exactly the same?!
 #else
       q->fc = store_class_entry ((zend_class_entry *) q->fc TSRMLS_CC);
 #endif
@@ -1131,9 +1130,10 @@ static int eaccelerator_stat(zend_file_h
     }
 
 	if (zend_is_executing(TSRMLS_C)) {
+        int tryname_length;
 		strncpy(tryname, zend_get_executed_filename(TSRMLS_C), MAXPATHLEN);
 		tryname[MAXPATHLEN - 1] = 0;
-		int tryname_length = strlen(tryname);
+		tryname_length = strlen(tryname);
 
 		while (tryname_length >= 0 && !IS_SLASH(tryname[tryname_length]))
 			tryname_length--;
@@ -1256,12 +1256,12 @@ ZEND_DLEXPORT zend_op_array* eaccelerato
   int   nreloads;
   time_t compile_time;
   int stat_result = 0;
+  struct timeval tv_start;
 
 #ifdef EACCELERATOR_USE_INODE
   realname[0] = '\000';
 #endif
 
-  struct timeval tv_start;
   ea_debug_printf(EA_TEST_PERFORMANCE, "[%d] Enter COMPILE\n",getpid());
   ea_debug_start_time(&tv_start);
   ea_debug_printf(EA_DEBUG, "[%d] Enter COMPILE\n",getpid());
@@ -1565,18 +1565,20 @@ static void profile_execute(zend_op_arra
 
   for (i=0;i<EAG(profile_level);i++)
     ea_debug_put(EA_PROFILE_OPCODES, "  ");
-  ea_debug_printf(EA_PROFILE_OPCODES, "enter: %s:%s\n", op_array->filename, op_array->function_name);
+  ea_debug_printf(EA_PROFILE_OPCODES, "enter profile_execute: %s:%s\n", op_array->filename, op_array->function_name);
   ea_debug_start_time(&tv_start);
   EAG(self_time)[EAG(profile_level)] = 0;
   EAG(profile_level)++;
+  ea_debug_printf(EA_PROFILE_OPCODES, "About to enter zend_execute...\n");
   mm_saved_zend_execute(op_array TSRMLS_CC);
+  ea_debug_printf(EA_PROFILE_OPCODES, "Finished zend_execute...\n");
   usec = ea_debug_elapsed_time(&tv_start);
   EAG(profile_level)--;
   if (EAG(profile_level) > 0)
     EAG(self_time)[EAG(profile_level)-1] += usec;
   for (i=0;i<EAG(profile_level);i++)
     ea_debug_put(EA_PROFILE_OPCODES, "  ");
-  ea_debug_printf(EA_PROFILE_OPCODES, "leave: %s:%s (%ld,%ld)\n", op_array->filename, op_array->function_name, usec, usec-EAG(self_time)[EAG(profile_level)]);
+  ea_debug_printf(EA_PROFILE_OPCODES, "leave profile_execute: %s:%s (%ld,%ld)\n", op_array->filename, op_array->function_name, usec, usec-EAG(self_time)[EAG(profile_level)]);
 }
 
 ZEND_DLEXPORT zend_op_array* profile_compile_file(zend_file_handle *file_handle, int type TSRMLS_DC) {
@@ -1593,7 +1595,7 @@ ZEND_DLEXPORT zend_op_array* profile_com
     EAG(self_time)[EAG(profile_level)-1] += usec;
   for (i=0;i<EAG(profile_level);i++)
     ea_debug_put(EA_PROFILE_OPCODES, "  ");
-  ea_debug_printf(EA_DEBUG, "compile: %s (%ld)\n", file_handle->filename, usec);
+  ea_debug_printf(EA_DEBUG, "zend_op_array compile: %s (%ld)\n", file_handle->filename, usec);
   return t;
 }
 
@@ -2023,9 +2025,16 @@ PHP_MINIT_FUNCTION(eaccelerator) {
 
     if (init_mm(TSRMLS_C) == FAILURE) {
       zend_error(E_CORE_WARNING,"[%s] Can not create shared memory area", EACCELERATOR_EXTENSION_NAME);
-      return FAILURE;
+      /* disable eA */
+      eaccelerator_mm_instance->enabled = 0;
     }
-
+#if 0
+    if (!eaccelerator_scripts_shm_only && check_cache_dir(EAG(cache_dir)) == FAILURE) {
+      zend_error(E_CORE_WARNING,"[%s] Can not init the cache directory", EACCELERATOR_EXTENSION_NAME);
+      /* disable eA */
+      eaccelerator_mm_instance->enabled = 0;
+    }
+#endif
     mm_saved_zend_compile_file = zend_compile_file;
 
 #ifdef DEBUG
