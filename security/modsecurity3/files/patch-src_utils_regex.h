--- src/utils/regex.h.orig	2020-01-13 13:09:28 UTC
+++ src/utils/regex.h
@@ -19,6 +19,7 @@
 #include <fstream>
 #include <string>
 #include <list>
+#include <vector>
 
 #ifndef SRC_UTILS_REGEX_H_
 #define SRC_UTILS_REGEX_H_
@@ -47,6 +48,16 @@ class SMatch {
     size_t m_offset;
 };
 
+struct SMatchCapture {
+    SMatchCapture(size_t group, size_t offset, size_t length) :
+    m_group(group),
+    m_offset(offset),
+    m_length(length) { }
+
+    size_t m_group; // E.g. 0 = full match; 6 = capture group 6
+    size_t m_offset; // offset of match within the analyzed string
+    size_t m_length;
+};
 
 class Regex {
  public:
@@ -58,6 +69,7 @@ class Regex {
     Regex& operator=(const Regex&) = delete;
 
     std::list<SMatch> searchAll(const std::string& s) const;
+    bool searchOneMatch(const std::string& s, std::vector<SMatchCapture>& captures) const;
     int search(const std::string &s, SMatch *m) const;
     int search(const std::string &s) const;
 
