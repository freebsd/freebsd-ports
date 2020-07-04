--- SLIP_LU/Source/slip_internal.h.orig	2020-07-03 16:11:39 UTC
+++ SLIP_LU/Source/slip_internal.h
@@ -660,11 +660,11 @@ static inline int64_t slip_cast_double_to_int64 (doubl
     {
         return (0) ;
     }
-    else if (x > INT64_MAX)
+    else if (x > (double)INT64_MAX)
     {
         return (INT64_MAX) ;
     }
-    else if (x < INT64_MIN)
+    else if (x < (double)INT64_MIN)
     {
         return (INT64_MIN) ;
     }
