--- pyctpp2/cengine.cc.orig	2012-01-19 08:46:23 UTC
+++ pyctpp2/cengine.cc
@@ -151,13 +151,13 @@ bool CEngine::Parse(const char *filename, CTemplate **
     string line;
     string pos;
 
-    int res = snprintf(buf, len, "%"PRIu32, static_cast<uint32_t>(e.GetLine()));
+    int res = snprintf(buf, len, "%" PRIu32, static_cast<uint32_t>(e.GetLine()));
     if (!(res < 0 || static_cast<size_t>(res) == len)) {
       line = string(buf);
     }
 
     memset(buf, 0, len);
-    res = snprintf(buf, len, "%"PRIu32, static_cast<uint32_t>(e.GetLinePos()));
+    res = snprintf(buf, len, "%" PRIu32, static_cast<uint32_t>(e.GetLinePos()));
     if (!(res < 0 || static_cast<size_t>(res) == len)) {
       pos = string(buf);
     }
@@ -198,13 +198,13 @@ bool CEngine::ParseText(const char *text, CTemplate **
     string line;
     string pos;
 
-    int res = snprintf(buf, len, "%"PRIu32, static_cast<uint32_t>(e.GetLine()));
+    int res = snprintf(buf, len, "%" PRIu32, static_cast<uint32_t>(e.GetLine()));
     if (!(res < 0 || static_cast<size_t>(res) == len)) {
       line = string(buf);
     }
 
     memset(buf, 0, len);
-    res = snprintf(buf, len, "%"PRIu32, static_cast<uint32_t>(e.GetLinePos()));
+    res = snprintf(buf, len, "%" PRIu32, static_cast<uint32_t>(e.GetLinePos()));
     if (!(res < 0 || static_cast<size_t>(res) == len)) {
       pos = string(buf);
     }
