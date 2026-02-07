--- src/rw_scan.c.orig	2020-04-23 08:44:17 UTC
+++ src/rw_scan.c
@@ -9,9 +9,9 @@ extern char const* PROG;
 
 extern char const* PROG;
 
-void rw_scan(tain_t* stamp, char const* text) {
+void rw_scan(tain* stamp, char const* text) {
   unsigned int i, scale;
-  uint64 u;
+  uint64_t u;
   char const* x;
   switch (text[0]) {
     case '$':
@@ -53,7 +53,7 @@ void rw_scan(tain_t* stamp, char const* text) {
       tai_unix(tain_secp(stamp), u);
       break;
     case 'i': {
-      localtmn_t loc;
+      localtmn loc;
       short dummy;
       ++text;
       i=localtmn_scan(text, &loc);
