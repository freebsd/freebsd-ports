--- src/common/strings/editing.h.orig	2019-06-22 10:06:04 UTC
+++ src/common/strings/editing.h
@@ -29,7 +29,7 @@ inline std::vector<std::string>
 split(std::string const &text,
       std::string const &pattern = ",",
       size_t max = 0) {
-  return split(text, boost::regex("\\Q"s + pattern, boost::regex::perl), max);
+  return ::split(text, boost::regex("\\Q"s + pattern, boost::regex::perl), max);
 }
 
 void strip(std::string &s, bool newlines = false);
