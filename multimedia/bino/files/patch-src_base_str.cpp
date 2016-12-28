--- src/base/str.cpp.orig	2012-10-13 05:01:40 UTC
+++ src/base/str.cpp
@@ -77,7 +77,7 @@ static inline std::string uint_to_str(T 
     do
     {
         // this assumes an ASCII-compatible character set
-        s.insert(0, 1, '0' + x % 10);
+        s.insert((size_t)0, (size_t)1, (char)('0' + x % 10));
         x /= 10;
     }
     while (x != 0);
@@ -94,7 +94,7 @@ static inline std::string int_to_str(T x
     do
     {
         // this assumes an ASCII-compatible character set
-        s.insert(0, 1, (negative ? ('0' - x % 10) : ('0' + x % 10)));
+        s.insert((size_t)0, (size_t)1, (char)(negative ? ('0' - x % 10) : ('0' + x % 10)));
         x /= 10;
     }
     while (x != 0);
