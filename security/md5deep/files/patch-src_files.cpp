--- src/files.cpp.orig	2018-02-10 07:48:06 UTC
+++ src/files.cpp
@@ -509,7 +509,7 @@ int state::parse_encase_file(const char 
         
 	    // Users expect the line numbers to start at one, not zero.
 	    if ((!ocb.opt_silent) || (mode_warn_only)) {
-		ocb.error("%s: No hash found in line %"PRIu32, fn, count + 1);
+		ocb.error("%s: No hash found in line %" PRIu32, fn, count + 1);
 		ocb.error("%s: %s", fn, strerror(errno));
 		return status_t::STATUS_USER_ERROR;
 	    }
@@ -542,7 +542,7 @@ int state::parse_encase_file(const char 
     }
 
     if (expected_hashes != count){
-	ocb.error("%s: Expecting %"PRIu32" hashes, found %"PRIu32"\n", 
+	ocb.error("%s: Expecting %" PRIu32" hashes, found %" PRIu32"\n", 
 			fn, expected_hashes, count);
     }
     return status_t::status_ok;
