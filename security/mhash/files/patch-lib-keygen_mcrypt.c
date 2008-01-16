diff -urN -x .svn ../../branches/vendor/mhash/lib/keygen_mcrypt.c ./lib/keygen_mcrypt.c
--- ../../branches/vendor/mhash/lib/keygen_mcrypt.c	2008-01-16 14:34:18.000000000 +0200
+++ ./lib/keygen_mcrypt.c	2008-01-16 15:26:44.000000000 +0200
@@ -52,8 +52,10 @@
 	
 	while (1) {
 		td = mhash_init(algorithm);
-		if (td == MHASH_FAILED)
+		if (td == MHASH_FAILED) {
+			mutils_free(key);
 			return(-MUTILS_INVALID_FUNCTION);
+		}
 		
 		if (salt_z == MUTILS_TRUE)
 			mhash(td, salt, salt_size);
@@ -66,8 +68,10 @@
 		digest = mhash_end(td);
 
 #if defined(MHASH_ROBUST)
-		if (digest == NULL)
+		if (digest == NULL) {
+			mutils_free(key);
 			return(-MUTILS_INVALID_RESULT);
+		}
 #endif
 
 		if (size > block_size) {
