--- src/util/configfile.cc.orig	2023-08-03 19:55:46 UTC
+++ src/util/configfile.cc
@@ -160,7 +160,8 @@ istream& ConfigFile::get(istream& s) {
   while (true) {
     getline(s, text);
     // Tolerate Doze "CRLF"-style line endings under Unix
-    if (text[text.length() - 1] == '\r') text.resize(text.length() - 1);
+    if (!text.empty() && text[text.length() - 1] == '\r')
+      text.resize(text.length() - 1);
     if (!s) break;
     push_back();
     swap(text, back());
