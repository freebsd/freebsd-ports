--- phalcon.zep.c.orig	2016-11-26 21:03:16 UTC
+++ phalcon.zep.c
@@ -2114,8 +2114,8 @@ static int ZEPHIR_FASTCALL zephir_memory
 #define ZEPHIR_MM_RESTORE() zephir_memory_restore_stack(NULL)
 
 #else
-static void ZEPHIR_FASTCALL zephir_memory_grow_stack();
-static int ZEPHIR_FASTCALL zephir_memory_restore_stack();
+static void zephir_memory_grow_stack();
+static int zephir_memory_restore_stack();
 
 #define ZEPHIR_MM_GROW() zephir_memory_grow_stack()
 #define ZEPHIR_MM_RESTORE() zephir_memory_restore_stack()
@@ -4212,7 +4212,7 @@ static void ZEPHIR_FASTCALL zephir_memor
 
 #else
 
-static void ZEPHIR_FASTCALL zephir_memory_grow_stack()
+static void zephir_memory_grow_stack()
 {
 	zend_zephir_globals_def *g = ZEPHIR_VGLOBAL;
 	if (g->start_memory == NULL) {
@@ -4221,7 +4221,7 @@ static void ZEPHIR_FASTCALL zephir_memor
 	zephir_memory_grow_stack_common(g);
 }
 
-static int ZEPHIR_FASTCALL zephir_memory_restore_stack()
+static int zephir_memory_restore_stack()
 {
 	zephir_memory_restore_stack_common(ZEPHIR_VGLOBAL);
 	return SUCCESS;
