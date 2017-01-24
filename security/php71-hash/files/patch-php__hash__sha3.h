--- php_hash_sha3.h.orig	2016-11-09 03:34:27 UTC
+++ php_hash_sha3.h
@@ -20,7 +20,7 @@
 #define PHP_HASH_SHA3_H
 
 #include "php.h"
-#include "ext/hash/php_hash.h"
+#include "php_hash.h"
 
 typedef struct {
 	unsigned char state[200]; // 5 * 5 * sizeof(uint64)
