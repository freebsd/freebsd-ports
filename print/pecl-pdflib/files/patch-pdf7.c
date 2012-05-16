--- pdf7.c	2010/04/28 12:17:58	298698
+++ pdf7.c	2012/02/25 12:27:38	323503
@@ -322,8 +322,9 @@
 {
     zend_object_value retval;
     pdflib_object *intern;
+#if PHP_VERSION_ID < 50399
     zval *tmp;
-
+#endif
 
     intern = emalloc(sizeof(pdflib_object));
     memset(intern, 0, sizeof(pdflib_object));
@@ -332,10 +333,14 @@
 
     ALLOC_HASHTABLE(intern->std.properties);
     zend_hash_init(intern->std.properties, 0, NULL, ZVAL_PTR_DTOR, 0);
+#if PHP_VERSION_ID < 50399
     zend_hash_copy(intern->std.properties,
             &class_type->default_properties,
             (copy_ctor_func_t) zval_add_ref,
             (void *) &tmp, sizeof(zval *));
+#else
+    object_properties_init( (zend_object*)intern, class_type );
+#endif
 
     retval.handle = zend_objects_store_put(intern,  NULL,
             (zend_objects_free_object_storage_t)pdflib_object_dtor,
