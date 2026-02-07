--- src/hash.cpp.orig	2014-01-29 18:40:39 UTC
+++ src/hash.cpp
@@ -124,7 +124,7 @@ bool file_data_hasher_t::compute_hash(ui
     
 	// If an error occured, display a message and see if we need to quit.
 	if ((current_read_bytes<0) || (this->handle && ferror(this->handle))){
-	    ocb->error_filename(this->file_name,"error at offset %"PRIu64": %s",
+	    ocb->error_filename(this->file_name,"error at offset %" PRIu64": %s",
 				request_start, strerror(errno));
 	   
 	    if (file_fatal_error()){
@@ -279,7 +279,7 @@ void file_data_hasher_t::hash()
 		MAP_FILE|
 #endif
 		MAP_SHARED,fd,0);
-	    if(fdht->base>0){		
+	    if(fdht->base != nullptr){		
 		/* mmap is successful, so set the bounds.
 		 * if it is not successful, we default to reading the fd
 		 */
