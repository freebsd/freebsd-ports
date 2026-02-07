--- src/rw-max.c.orig	2022-08-10 16:08:24 UTC
+++ src/rw-max.c
@@ -7,7 +7,7 @@
 char const* PROG="rw-max";
 
 int main(int argc, char** argv) {
-  tain_t t0, t1;
+  tain t0, t1;
   RW_ARG_CHECK(2, " stamp1 stamp2");
   rw_scan(&t0, argv[1]);
   rw_scan(&t1, argv[2]);
