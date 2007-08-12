--- ssh2.c	2006-06-07 19:35:34.000000000 +0200
+++ ssh2.c.oden	2007-08-07 17:32:29.000000000 +0200
@@ -484,7 +484,7 @@
 
 	ZEND_FETCH_RESOURCE(session, LIBSSH2_SESSION*, &zsession, -1, PHP_SSH2_SESSION_RES_NAME, le_ssh2_session);
 
-#if LIBSSH2_APINO < 200412301450
+#if LIBSSH2_VERSION_NUM < 0x001000
 	libssh2_session_methods(session, &kex, &hostkey, &crypt_cs, &crypt_sc, &mac_cs, &mac_sc, &comp_cs, &comp_sc, &lang_cs, &lang_sc);
 #else
 	kex = libssh2_session_methods(session, LIBSSH2_METHOD_KEX);
