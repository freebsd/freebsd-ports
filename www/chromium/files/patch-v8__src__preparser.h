--- v8/src/preparser.h.orig	2014-10-10 09:16:50 UTC
+++ v8/src/preparser.h
@@ -450,7 +450,7 @@
   void ReportMessageAt(Scanner::Location location, const char* message,
                        bool is_reference_error = false) {
     Traits::ReportMessageAt(location, message,
-                            reinterpret_cast<const char*>(NULL),
+                            reinterpret_cast<const char*>(__null),
                             is_reference_error);
   }
 
