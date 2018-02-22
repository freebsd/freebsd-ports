--- src/hashlist.cpp.orig	2018-02-10 07:50:51 UTC
+++ src/hashlist.cpp
@@ -342,7 +342,7 @@ hashlist::load_hash_file(display *ocb,co
     file_data_t *t = new (std::nothrow) file_data_t();
     if (NULL == t)
     {
-      ocb->fatal_error("%s: Out of memory in line %"PRIu64,
+      ocb->fatal_error("%s: Out of memory in line %" PRIu64,
 		       fn.c_str(), line_number);
     }
 
@@ -390,7 +390,7 @@ hashlist::load_hash_file(display *ocb,co
       if ( !algorithm_t::valid_hash(hash_column[column_number],word))
       {
 	if (ocb)
-	  ocb->error("%s: Invalid %s hash in line %"PRIu64,
+	  ocb->error("%s: Invalid %s hash in line %" PRIu64,
 		     fn.c_str(),
 		     hashes[hash_column[column_number]].name.c_str(),
 		     line_number);
