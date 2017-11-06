--- src/hash.cpp.orig	2014-01-29 18:40:39 UTC
+++ src/hash.cpp
@@ -279,7 +279,7 @@ void file_data_hasher_t::hash()
 		MAP_FILE|
 #endif
 		MAP_SHARED,fd,0);
-	    if(fdht->base>0){		
+	    if(fdht->base != nullptr){		
 		/* mmap is successful, so set the bounds.
 		 * if it is not successful, we default to reading the fd
 		 */
