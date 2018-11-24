--- src/io/WriteNCDF.cpp.orig	2018-11-23 06:26:09 UTC
+++ src/io/WriteNCDF.cpp
@@ -161,8 +161,8 @@ void WriteNCDF::time_and_date(char* time
    strftime(date_string, TIME_STR_LEN, "%m/%d/%Y", local_time);
 
    // Terminate with NULL character
-   time_string[10] = (char)NULL;
-   date_string[10] = (char)NULL;
+   time_string[10] = (char)0;
+   date_string[10] = (char)0;
 }
 
 ErrorCode WriteNCDF::write_file(const char *exodus_file_name,
