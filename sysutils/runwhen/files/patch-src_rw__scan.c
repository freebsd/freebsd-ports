--- src/rw_scan.c.orig	2022-08-10 16:08:50 UTC
+++ src/rw_scan.c
@@ -9,7 +9,7 @@
 
 extern char const* PROG;
 
-void rw_scan(tain_t* stamp, char const* text) {
+void rw_scan(tain* stamp, char const* text) {
   unsigned int i, scale;
   uint64 u;
   char const* x;
@@ -53,7 +53,7 @@ void rw_scan(tain_t* stamp, char const* text) {
       tai_unix(tain_secp(stamp), u);
       break;
     case 'i': {
-      localtmn_t loc;
+      localtmn loc;
       short dummy;
       ++text;
       i=localtmn_scan(text, &loc);
