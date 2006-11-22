--- xcache.c (revision 278)
+++ xcache.c (revision 283)
@@ -1582,10 +1582,9 @@
 	long id = 0;
 
+	xcache_admin_auth_check(TSRMLS_C);
+
 	if (!xc_initized) {
-		php_error_docref(NULL TSRMLS_CC, E_WARNING, "XCache is not initized");
-		RETURN_FALSE;
-	}
-
-	xcache_admin_auth_check(TSRMLS_C);
+		RETURN_NULL();
+	}
 
 	if (optype == XC_OP_COUNT) {
@@ -2365,10 +2364,4 @@
 }
 
-/* dirty check */
-#if defined(COMPILE_DL_XCACHE) && (defined(ZEND_WIN32) || defined(__CYGWIN__) || defined(__MINGW32__))
-#	define zend_append_version_info(x) do { } while (0)
-#else
-extern void zend_append_version_info(zend_extension *extension);
-#endif
 static int xc_zend_extension_startup(zend_extension *extension)
 {
@@ -2377,5 +2370,4 @@
 			return FAILURE;
         }
-        zend_append_version_info(extension);
     }
 	return SUCCESS;
@@ -2640,5 +2632,5 @@
 {
 	if (xc_zend_extension_gotup) {
-		return FAILURE;
+		return SUCCESS;
 	}
 	xc_zend_extension_gotup = 1;
