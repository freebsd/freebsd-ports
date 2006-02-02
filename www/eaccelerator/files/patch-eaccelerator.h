--- eaccelerator.h.orig	Mon Jul 11 19:25:38 2005
+++ eaccelerator.h	Thu Feb  2 09:40:00 2006
@@ -44,6 +44,10 @@
 #  endif
 #endif
 
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION >= 1
+#   define ZEND_ENGINE_2_1
+#endif
+
 /* fixes compile errors on php5.1 */
 #ifdef STR_EMPTY_ALLOC
 #define empty_string STR_EMPTY_ALLOC()
@@ -166,12 +170,14 @@
 
 #define MAX_DUP_STR_LEN 256
 
+/******************************************************************************/
+
+#endif /* HAVE_EACCELERATOR_STANDALONE_LOADER */
+
 #ifndef offsetof
 #  define offsetof(str,fld) ((size_t)&(((str*)NULL)->fld))
 #endif
 
-/******************************************************************************/
-
 typedef struct _eaccelerator_op_array {
 	zend_uchar type;
 #ifdef ZEND_ENGINE_2
@@ -197,6 +203,10 @@ typedef struct _eaccelerator_op_array {
 #endif
 	zend_op *opcodes;
 	zend_uint last;
+#ifdef ZEND_ENGINE_2_1
+	zend_compiled_variable *vars;
+    int last_var;
+#endif
 	zend_uint T;
 	zend_brk_cont_element *brk_cont_array;
 	zend_uint last_brk_cont;
@@ -218,24 +228,29 @@ typedef struct _eaccelerator_class_entry
 	char type;
 	char *name;
 	char *name_lc;
-	uint name_length;
+	zend_uint name_length;
 	char *parent;
 	HashTable function_table;
 	HashTable default_properties;
 #ifdef ZEND_ENGINE_2
-	zend_uint ce_flags;
-	HashTable *static_members;
 	HashTable properties_info;
+#  ifdef ZEND_ENGINE_2_1
+	HashTable default_static_members;
+#  endif
+	HashTable *static_members;
 	HashTable constants_table;
+	zend_uint ce_flags;
 	zend_uint num_interfaces;
+
 	char **interfaces;
 	zend_class_iterator_funcs iterator_funcs;
 
-	 zend_object_value (*create_object) (zend_class_entry *
-										 class_type TSRMLS_DC);
-	zend_object_iterator *(*get_iterator) (zend_class_entry * ce,
-										   zval * object TSRMLS_DC);
-	int (*interface_gets_implemented) (zend_class_entry * iface, zend_class_entry * class_type TSRMLS_DC);	/* a class implements this interface */
+	/* handlers */
+	zend_object_value (*create_object) (zend_class_entry *class_type TSRMLS_DC);
+	zend_object_iterator *(*get_iterator) (zend_class_entry *ce, zval *object TSRMLS_DC);
+	int (*interface_gets_implemented) (zend_class_entry *iface, zend_class_entry *class_type TSRMLS_DC);	/* a class implements this interface */
+
+	/* hra: serializer callbacks may need to be added here in the future for php 5.1 */
 
 	char *filename;
 	zend_uint line_start;
@@ -255,6 +270,8 @@ typedef struct _mm_fc_entry {
 	char htabkey[1];			/* must be last element */
 } mm_fc_entry;
 
+#ifndef HAVE_EACCELERATOR_STANDALONE_LOADER
+
 /*
  * A mm_cache_entry is a bucket for one PHP script file.
  * Nested  functions and classes which defined in the file goes
@@ -381,17 +398,13 @@ void *eaccelerator_malloc2 (size_t size 
 unsigned int eaccelerator_crc32 (const char *p, size_t n);
 int eaccelerator_md5 (char *s, const char *prefix, const char *key TSRMLS_DC);
 
-void restore_zval (zval * TSRMLS_DC);
 void calc_zval (zval * z TSRMLS_DC);
 void store_zval (zval * z TSRMLS_DC);
 void fixup_zval (zval * z TSRMLS_DC);
+void restore_zval (zval * TSRMLS_DC);
 
 unsigned int hash_mm(const char *data, int len); 
 
-#  ifdef WITH_EACCELERATOR_EXECUTOR
-ZEND_DLEXPORT void eaccelerator_execute (zend_op_array * op_array TSRMLS_DC);
-#  endif
-
 #  ifdef WITH_EACCELERATOR_OPTIMIZER
 void eaccelerator_optimize (zend_op_array * op_array);
 #  endif
@@ -399,15 +412,13 @@ void eaccelerator_optimize (zend_op_arra
 #ifdef WITH_EACCELERATOR_ENCODER
 PHP_FUNCTION (eaccelerator_encode);
 #endif
-#endif /* HAVE_EACCELERATOR_LOADER_STANDALONE */
+#endif /* HAVE_EACCELERATOR_STANDALONE_LOADER */
 
 #ifdef ZTS
 #  define EAG(v) TSRMG(eaccelerator_globals_id, zend_eaccelerator_globals*, v)
 #else
 #  define EAG(v) (eaccelerator_globals.v)
 #endif
-
-#define MMCG(v) EAG(v)
 
 /*
  * conditional filter
