--- mecab7.c.orig	2015-12-05 16:08:55 UTC
+++ mecab7.c
@@ -1456,7 +1456,7 @@ static PHP_FUNCTION(mecab_new)
 	if (zoptions != NULL) {
 		int getopt_result = 0;
 		zend_string *key;
-		ulong num_key;
+		zend_ulong num_key;
 		zval *entry;
 
 		ALLOC_HASHTABLE(options);
