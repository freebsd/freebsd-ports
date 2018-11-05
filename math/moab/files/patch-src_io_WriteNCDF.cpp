--- src/io/WriteNCDF.cpp.orig	2018-11-05 01:47:40 UTC
+++ src/io/WriteNCDF.cpp
@@ -154,8 +154,8 @@ void WriteNCDF::time_and_date(char* time
    strftime(date_string, TIME_STR_LEN, "%m/%d/%Y", local_time);
 
      // terminate with NULL character
-   time_string[10] = (char)NULL;
-   date_string[10] = (char)NULL;
+   time_string[10] = (char)0;
+   date_string[10] = (char)0;
 }
 
 ErrorCode WriteNCDF::write_file(const char *exodus_file_name, 
