--- src/network.c.orig	2016-05-11 21:04:11 UTC
+++ src/network.c
@@ -72,7 +72,7 @@ skipline(char *text) {
 }
 
 static char*
-getline(char *text) {
+get_line(char *text) {
   int len;
   char *str;
 
@@ -113,10 +113,10 @@ parse_response(char *buf) {
   int read_keys = 0;
 
   while (*buf) {
-    key = getline(buf);
+    key = get_line(buf);
     buf = skipline(buf);
     if (*buf) {
-      val = getline(buf);
+      val = get_line(buf);
       buf = skipline(buf);
 
       g_hash_table_insert(hash, g_strdup(key), g_strdup(val));
