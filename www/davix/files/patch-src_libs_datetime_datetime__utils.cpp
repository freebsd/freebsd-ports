--- src/libs/datetime/datetime_utils.cpp.orig	2018-06-16 07:41:55 UTC
+++ src/libs/datetime/datetime_utils.cpp
@@ -19,6 +19,7 @@
 */
 
 #include <davix_internal_config.hpp>
+#include <sys/time.h>
 #include "datetime_utils.hpp"
 
 time_t parse_http_date(const char* http_date){
@@ -32,7 +33,15 @@ time_t parse_http_date(const char* http_
     if ( p == NULL || *p != '\0'){
         return -1;
     }
-    return mktime(&tm) - timezone;;
+    int _timezone = 0;
+    {
+      struct timeval tv;
+      struct timezone tz;
+      gettimeofday( &tv, &tz );
+      _timezone = -tz.tz_minuteswest * 60;
+    }
+
+    return mktime(&tm) - _timezone;;
 
 }
 
@@ -70,8 +79,15 @@ time_t parse_iso8601date(const char* iso
         }
     }
 
+    int _timezone = 0;
+    {
+      struct timeval tv;
+      struct timezone tz;
+      gettimeofday( &tv, &tz );
+      _timezone = -tz.tz_minuteswest * 60;
+    }
 
-    return mktime(&tm_time) - timezone;
+    return mktime(&tm_time) - _timezone;
 
 }
 
