--- eaccelerator.c.orig	Thu Nov 24 07:59:33 2005
+++ eaccelerator.c	Thu Nov 24 08:00:58 2005
@@ -1131,9 +1131,10 @@
     }
 
 	if (zend_is_executing(TSRMLS_C)) {
+		int tryname_length;
 		strncpy(tryname, zend_get_executed_filename(TSRMLS_C), MAXPATHLEN);
 		tryname[MAXPATHLEN - 1] = 0;
-		int tryname_length = strlen(tryname);
+		tryname_length = strlen(tryname);
 
 		while (tryname_length >= 0 && !IS_SLASH(tryname[tryname_length]))
 			tryname_length--;
@@ -1256,12 +1257,12 @@
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
