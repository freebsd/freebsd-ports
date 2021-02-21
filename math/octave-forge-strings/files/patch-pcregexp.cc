--- pcregexp.cc.orig	2021-02-21 23:21:29 UTC
+++ pcregexp.cc
@@ -49,7 +49,7 @@ Check your system's @code{pcre} man page.\n\
     std::string pattern = args(0).string_value();
     std::string input = args(1).string_value();
     if (error_state) {
-        gripe_wrong_type_arg("pcregexp", args(0));
+        err_wrong_type_arg("pcregexp", args(0));
         return retval;
     }
 
