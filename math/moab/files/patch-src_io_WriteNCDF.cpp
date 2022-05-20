- workaround for https://bitbucket.org/fathomteam/moab/issues/157/please-do-not-convert-null-to-char-this

--- src/io/WriteNCDF.cpp.orig	2021-11-12 00:54:52 UTC
+++ src/io/WriteNCDF.cpp
@@ -160,8 +160,8 @@ void WriteNCDF::time_and_date( char* time_string, char
     strftime( date_string, TIME_STR_LEN, "%m/%d/%Y", local_time );
 
     // Terminate with NULL character
-    time_string[10] = (char)NULL;
-    date_string[10] = (char)NULL;
+    time_string[10] = (char)0;
+    date_string[10] = (char)0;
 }
 
 ErrorCode WriteNCDF::write_file( const char* exodus_file_name, const bool overwrite, const FileOptions& opts,
