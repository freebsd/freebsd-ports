--- utils.h.orig	2018-11-02 06:39:45 UTC
+++ utils.h
@@ -67,7 +67,11 @@ namespace Utils {
 
   inline std::string int_to_string(int a)
   {
-    return static_cast< std::ostringstream & >(( std::ostringstream() << std::dec << a ) ).str();
+    // see https://www.cfdem.com/forums/error-non-const-lvalue-reference-type-basicostringstream-cannot-bind-temporary-type
+    // return static_cast< std::ostringstream & >(( std::ostringstream() << std::dec << a ) ).str();
+    std::ostringstream ss;
+    ss << std::dec << a;
+    return ss.str();
   }
 
   inline std::string double_to_string(double dbl)
