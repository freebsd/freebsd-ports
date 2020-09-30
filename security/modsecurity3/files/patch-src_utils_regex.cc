--- src/utils/regex.cc.orig	2020-01-13 13:09:28 UTC
+++ src/utils/regex.cc
@@ -16,10 +16,6 @@
 #include "src/utils/regex.h"
 
 #include <pcre.h>
-#include <sys/socket.h>
-#include <sys/types.h>
-#include <netinet/in.h>
-#include <arpa/inet.h>
 #include <string>
 #include <list>
 
@@ -99,6 +95,26 @@ std::list<SMatch> Regex::searchAll(const
     return retList;
 }
 
+bool Regex::searchOneMatch(const std::string& s, std::vector<SMatchCapture>& captures) const {
+    const char *subject = s.c_str();
+    int ovector[OVECCOUNT];
+
+    int rc = pcre_exec(m_pc, m_pce, subject, s.size(), 0, 0, ovector, OVECCOUNT);
+
+    for (int i = 0; i < rc; i++) {
+        size_t start = ovector[2*i];
+        size_t end = ovector[2*i+1];
+        size_t len = end - start;
+        if (end > s.size()) {
+            continue;
+        }
+        SMatchCapture capture(i, start, len);
+        captures.push_back(capture);
+    }
+
+    return (rc > 0);
+}
+
 int Regex::search(const std::string& s, SMatch *match) const {
     int ovector[OVECCOUNT];
     int ret = pcre_exec(m_pc, m_pce, s.c_str(),
