--- zmq.c.orig	2016-02-01 01:50:43 UTC
+++ zmq.c
@@ -235,7 +235,11 @@ php_zmq_context *php_zmq_context_get(zend_long io_thre
 		le.type = php_zmq_context_list_entry();
 		le.ptr  = context;
 
+#if PHP_VERSION_ID < 70300
 		GC_REFCOUNT(&le) = 1;
+#else
+		GC_SET_REFCOUNT(&le, 1);
+#endif
 
 		/* plist_key is not a persistent allocated key, thus we use str_update here */
 		if (zend_hash_str_update_mem(&EG(persistent_list), plist_key->val, plist_key->len, &le, sizeof(le)) == NULL) {
@@ -535,7 +539,11 @@ void php_zmq_socket_store(php_zmq_socket *zmq_sock_p, 
 	le.type = php_zmq_socket_list_entry();
 	le.ptr  = zmq_sock_p;
 
+#if PHP_VERSION_ID < 70300
 	GC_REFCOUNT(&le) = 1;
+#else
+	GC_SET_REFCOUNT(&le, 1);
+#endif
 
 	plist_key = php_zmq_socket_plist_key(type, persistent_id, use_shared_ctx);
 
