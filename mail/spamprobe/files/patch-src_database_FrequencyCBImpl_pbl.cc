--- src/database/FrequencyDBImpl_pbl.cc	2006-11-17 02:24:48.000000000 -0500
+++ src/database/FrequencyDBImpl_pbl.cc	2009-09-30 16:08:39.000000000 -0400
@@ -45,6 +45,6 @@
 const char *FrequencyDBImpl_pbl::SEARCH_SUFFIX("pkey");
 
-inline int throw_on_error(const char *function_name,
-                          int rc)
+inline long throw_on_error(const char *function_name,
+                          long rc)
 {
   if (rc >= 0) {
@@ -261,6 +261,6 @@
 {
   char key[BUFFER_SIZE];
-  int keylen = 0;
-  int rc = 0;
+  size_t keylen;
+  int rc;
 
   switch (pbl_code) {

