Description: Fix two minor memory leaks.
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: http://sourceforge.net/mailarchive/message.php?msg_name=20090910102100.GA26539%40straylight.m.ringlet.net
Last-Update: 2009-09-10


--- lib/keygen_mcrypt.c.orig
+++ lib/keygen_mcrypt.c
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
