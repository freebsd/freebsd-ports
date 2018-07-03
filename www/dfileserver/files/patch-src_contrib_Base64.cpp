--- src/contrib/Base64.cpp.orig	2005-09-30 05:15:19 UTC
+++ src/contrib/Base64.cpp
@@ -27,11 +27,12 @@ static string       cvt = "ABCDEFGHIJKLM
 
 string Base64::encode(string data)
 {
-    auto     string::size_type  i;
-    auto     char               c;
-    auto     string::size_type  len = data.length();
-    auto     string             ret;
+    std::string::size_type  i;
+    std::string::size_type  len;
+    char               c;
+    string             ret;
 
+    len = data.length();
     for (i = 0; i < len; ++i)
     {
         c = (data[i] >> 2) & 0x3f;
@@ -71,11 +72,11 @@ string Base64::encode(string data)
 
 string Base64::decode(string data)
 {
-    auto     string::size_type  i;
-    auto     char               c;
-    auto     char               c1;
-    auto     string::size_type  len = data.length();
-    auto     string             ret;
+    string::size_type  i;
+    char               c;
+    char               c1;
+    string::size_type  len = data.length();
+    string             ret;
 
     for (i = 0; i < len; ++i)
     {
