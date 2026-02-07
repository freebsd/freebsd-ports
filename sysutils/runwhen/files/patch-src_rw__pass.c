--- src/rw_pass.c.orig	2022-08-10 16:08:24 UTC
+++ src/rw_pass.c
@@ -9,7 +9,7 @@
 
 extern char const* PROG;
 
-void rw_pass(tain_t const* t, char** argv) {
+void rw_pass(tain const* t, char** argv) {
   char buf[2*TAIN_PACK+1];
 
   buf[tain_fmt(buf, t)]='\0';
