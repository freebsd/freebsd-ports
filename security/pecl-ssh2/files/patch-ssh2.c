--- ./ssh2.c.orig	2007-08-11 23:25:25.000000000 -0400
+++ ./ssh2.c	2010-04-13 09:05:17.000000000 -0400
@@ -48,7 +48,6 @@
 #endif
 
 #ifdef ZEND_ENGINE_2
-static
     ZEND_BEGIN_ARG_INFO(php_ssh2_first_arg_force_ref, 0)
         ZEND_ARG_PASS_INFO(1)
     ZEND_END_ARG_INFO()
@@ -484,7 +483,7 @@
 
 	ZEND_FETCH_RESOURCE(session, LIBSSH2_SESSION*, &zsession, -1, PHP_SSH2_SESSION_RES_NAME, le_ssh2_session);
 
-#if LIBSSH2_APINO < 200412301450
+#if LIBSSH2_VERSION_NUM < 0x001000
 	libssh2_session_methods(session, &kex, &hostkey, &crypt_cs, &crypt_sc, &mac_cs, &mac_sc, &comp_cs, &comp_sc, &lang_cs, &lang_sc);
 #else
 	kex = libssh2_session_methods(session, LIBSSH2_METHOD_KEX);
@@ -889,7 +888,7 @@
 	for(i = 0; i < numfds; i++) {
 		zval *subarray = *pollmap[i];
 
-		if (!subarray->is_ref && subarray->refcount > 1) {
+		if (!Z_ISREF_P(subarray) && Z_REFCOUNT_P(subarray) > 1) {
 			/* Make a new copy of the subarray zval* */
 			MAKE_STD_ZVAL(subarray);
 			*subarray = **pollmap[i];
@@ -899,8 +898,8 @@
 			zval_copy_ctor(subarray);
 
 			/* Fixup its refcount */
-			subarray->is_ref = 0;
-			subarray->refcount = 1;
+			Z_UNSET_ISREF_P(subarray);
+			Z_SET_REFCOUNT_P(subarray, 1);
 		}
 		zend_hash_del(Z_ARRVAL_P(subarray), "revents", sizeof("revents"));
 		add_assoc_long(subarray, "revents", pollfds[i].revents);
@@ -1009,8 +1008,8 @@
 			}
 
 			zval_copy_ctor(&copyval);
-			copyval.is_ref = 0;
-			copyval.refcount = 1;
+			Z_UNSET_ISREF(copyval);
+			Z_SET_REFCOUNT(copyval, 1);
 			convert_to_string(&copyval);
 
 			if (*key == '*') {
