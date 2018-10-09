--- zmq_pollset.c.orig	2016-02-01 01:50:43 UTC
+++ zmq_pollset.c
@@ -169,7 +169,7 @@ static
 zend_string *s_create_key(zval *entry)
 {
 	if (Z_TYPE_P(entry) == IS_RESOURCE) {
-		return strpprintf(0, "r:%ld", Z_RES_P(entry)->handle);
+		return strpprintf(0, "r:%d", Z_RES_P(entry)->handle);
 	}
 	else {
 		zend_string *hash = php_spl_object_hash(entry);
@@ -222,7 +222,7 @@ size_t php_zmq_pollset_num_items(php_zmq_pollset *set)
 zend_string *php_zmq_pollset_add(php_zmq_pollset *set, zval *entry, int events, int *error) 
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
