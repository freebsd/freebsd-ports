--- src/convert_case.c.orig	2022-02-16 14:49:42 UTC
+++ src/convert_case.c
@@ -45,7 +45,7 @@ int strtolower(lua_State *l) {
   int32_t out_len = u_strToLower(dest, str_len, str, str_len, "", &status);
   if(U_FAILURE(status)) {
     // Allocate more memory if necessary
-    if(status = U_BUFFER_OVERFLOW_ERROR) {
+    if(status == U_BUFFER_OVERFLOW_ERROR) {
       free(dest);
       dest = malloc(sizeof(UChar) * (out_len + 1));
       if(!dest) {
@@ -109,7 +109,7 @@ int strtoupper(lua_State *l) {
   int32_t out_len = u_strToUpper(dest, str_len, str, str_len, "", &status);
   if(U_FAILURE(status)) {
     // Allocate more memory if necessary
-    if(status = U_BUFFER_OVERFLOW_ERROR) {
+    if(status == U_BUFFER_OVERFLOW_ERROR) {
       free(dest);
       dest = malloc(sizeof(UChar) * (out_len + 1));
       if(!dest) {
@@ -173,7 +173,7 @@ int strtotitle(lua_State *l) {
   int32_t out_len = u_strToTitle(dest, str_len, str, str_len, NULL, "", &status);
   if(U_FAILURE(status)) {
     // Allocate more memory if necessary
-    if(status = U_BUFFER_OVERFLOW_ERROR) {
+    if(status == U_BUFFER_OVERFLOW_ERROR) {
       free(dest);
       dest = malloc(sizeof(UChar) * (out_len + 1));
       if(!dest) {
