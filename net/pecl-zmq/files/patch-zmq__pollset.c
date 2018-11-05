--- zmq_pollset.c.orig	2018-10-16 14:37:44 UTC
+++ zmq_pollset.c
@@ -38,7 +38,7 @@
 
 /* {{{ typedef struct _php_zmq_pollset 
 */
-typedef struct _php_zmq_pollset {
+struct _php_zmq_pollset {
 
 	zmq_pollitem_t *items;
 	zend_string **keys;
@@ -49,11 +49,11 @@ typedef struct _php_zmq_pollset {
 	size_t alloc_size;
 
 	zval errors;
-} php_zmq_pollset;
+}; 
 /* }}} */
 
 static
-void s_pollset_clear(php_zmq_pollset *set, zend_bool reinit)
+void s_pollset_clear(struct _php_zmq_pollset *set, zend_bool reinit)
 {
 	size_t i;
 
@@ -85,7 +85,7 @@ void s_pollset_clear(php_zmq_pollset *set, zend_bool r
 }
 
 static
-size_t s_pollset_append(php_zmq_pollset *set, zmq_pollitem_t *item, zend_string *key, zval *entry)
+size_t s_pollset_append(struct _php_zmq_pollset *set, zmq_pollitem_t *item, zend_string *key, zval *entry)
 {
 	size_t index = set->num_items;
 
@@ -109,7 +109,7 @@ size_t s_pollset_append(php_zmq_pollset *set, zmq_poll
 }
 
 static
-void s_pollset_delete(php_zmq_pollset *set, size_t index)
+void s_pollset_delete(struct _php_zmq_pollset *set, size_t index)
 {
 	zend_string_release(set->keys[index]);
 	zval_ptr_dtor(&set->zv[index]);
@@ -144,7 +144,7 @@ void s_pollset_delete(php_zmq_pollset *set, size_t ind
 }
 
 static
-zend_bool s_index_for_key(php_zmq_pollset *set, zend_string *key, size_t *index)
+zend_bool s_index_for_key(struct _php_zmq_pollset *set, zend_string *key, size_t *index)
 {
 	zend_bool retval = 0;
 	size_t i;
@@ -160,7 +160,7 @@ zend_bool s_index_for_key(php_zmq_pollset *set, zend_s
 }
 
 static
-zval *s_zval_for_index(php_zmq_pollset *set, size_t index)
+zval *s_zval_for_index(struct _php_zmq_pollset *set, size_t index)
 {
 	return &set->zv[index];
 }
@@ -169,7 +169,7 @@ static
 zend_string *s_create_key(zval *entry)
 {
 	if (Z_TYPE_P(entry) == IS_RESOURCE) {
-		return strpprintf(0, "r:%ld", Z_RES_P(entry)->handle);
+		return strpprintf(0, "r:%d", Z_RES_P(entry)->handle);
 	}
 	else {
 		zend_string *hash = php_spl_object_hash(entry);
@@ -179,9 +179,9 @@ zend_string *s_create_key(zval *entry)
 	}
 }
 
-php_zmq_pollset *php_zmq_pollset_init()
+struct _php_zmq_pollset *_php_zmq_pollset_init()
 {
-	php_zmq_pollset *set = ecalloc (1, sizeof(php_zmq_pollset));
+	struct _php_zmq_pollset *set = ecalloc (1, sizeof(struct _php_zmq_pollset));
 
 	array_init(&set->errors);
 
@@ -195,7 +195,7 @@ php_zmq_pollset *php_zmq_pollset_init()
 	return set;
 }
 
-zend_bool php_zmq_pollset_items(php_zmq_pollset *set, zval *return_value)
+zend_bool php_zmq_pollset_items(struct _php_zmq_pollset *set, zval *return_value)
 {
 	size_t i;
 
@@ -214,15 +214,15 @@ zend_bool php_zmq_pollset_items(php_zmq_pollset *set, 
 	return 1;
 }
 
-size_t php_zmq_pollset_num_items(php_zmq_pollset *set)
+size_t php_zmq_pollset_num_items(struct _php_zmq_pollset *set)
 {
 	return set->num_items;
 }
 
-zend_string *php_zmq_pollset_add(php_zmq_pollset *set, zval *entry, int events, int *error) 
+zend_string *php_zmq_pollset_add(struct _php_zmq_pollset *set, zval *entry, int events, int *error) 
 {
 	zend_string *key;
-	size_t num_items, index;
+	size_t index;
 	zmq_pollitem_t item;
 
 	*error = 0;
@@ -233,7 +233,7 @@ zend_string *php_zmq_pollset_add(php_zmq_pollset *set,
 		return key;
 	}
 
-	num_items = php_zmq_pollset_num_items(set);
+	php_zmq_pollset_num_items(set);
 	memset(&item, 0, sizeof(zmq_pollitem_t));
 
 	if (Z_TYPE_P(entry) == IS_RESOURCE) {
@@ -273,7 +273,7 @@ zend_string *php_zmq_pollset_add(php_zmq_pollset *set,
 	return key;
 }
 
-zend_bool php_zmq_pollset_delete_by_key(php_zmq_pollset *set, zend_string *key)
+zend_bool php_zmq_pollset_delete_by_key(struct _php_zmq_pollset *set, zend_string *key)
 {
 	size_t index;
 
@@ -285,7 +285,7 @@ zend_bool php_zmq_pollset_delete_by_key(php_zmq_pollse
 	return 1;
 }
 
-zend_bool php_zmq_pollset_delete(php_zmq_pollset *set, zval *entry)
+zend_bool php_zmq_pollset_delete(struct _php_zmq_pollset *set, zval *entry)
 {
 	zend_bool retval;
 	zend_string *key = s_create_key(entry);
@@ -296,7 +296,7 @@ zend_bool php_zmq_pollset_delete(php_zmq_pollset *set,
 	return retval;
 }
 
-int php_zmq_pollset_poll(php_zmq_pollset *set, int timeout, zval *r_array, zval *w_array)
+int php_zmq_pollset_poll(struct _php_zmq_pollset *set, int timeout, zval *r_array, zval *w_array)
 {
 	int rc, i;
 	zend_bool readable = 0, writable = 0;
@@ -354,7 +354,7 @@ int php_zmq_pollset_poll(php_zmq_pollset *set, int tim
 	return rc;
 }
 
-void php_zmq_pollset_clear(php_zmq_pollset *set)
+void php_zmq_pollset_clear(struct _php_zmq_pollset *set)
 {
 	// Clear errors
 	zend_hash_clean(Z_ARRVAL(set->errors));
@@ -363,14 +363,14 @@ void php_zmq_pollset_clear(php_zmq_pollset *set)
 	s_pollset_clear(set, 1);
 }
 
-zval *php_zmq_pollset_errors(php_zmq_pollset *set)
+zval *php_zmq_pollset_errors(struct _php_zmq_pollset *set)
 {
 	return &set->errors;
 }
 
-void php_zmq_pollset_destroy(php_zmq_pollset **ptr)
+void php_zmq_pollset_destroy(struct _php_zmq_pollset **ptr)
 {
-	php_zmq_pollset *set = *ptr;
+	struct _php_zmq_pollset *set = *ptr;
 
 	// clear the pollset
 	s_pollset_clear(set, 0);
