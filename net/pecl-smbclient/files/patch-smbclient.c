--- smbclient.c.orig	2023-04-17 03:27:10 UTC
+++ smbclient.c
@@ -1202,7 +1202,7 @@ PHP_FUNCTION(smbclient_read)
 		return;
 	}
 	if (count < 0) {
-		php_error(E_WARNING, "Negative byte count: %ld", count);
+		php_error(E_WARNING, "Negative byte count: " ZEND_LONG_FMT, count);
 		RETURN_FALSE;
 	}
 	STATE_FROM_ZSTATE;
@@ -1253,7 +1253,7 @@ PHP_FUNCTION(smbclient_write)
 		return;
 	}
 	if (count < 0) {
-		php_error(E_WARNING, "Negative byte count: %ld", count);
+		php_error(E_WARNING, "Negative byte count: " ZEND_LONG_FMT, count);
 		RETURN_FALSE;
 	}
 	if (count == 0 || count > str_len) {
