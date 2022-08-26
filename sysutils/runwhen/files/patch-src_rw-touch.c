--- src/rw-touch.c.orig	2022-08-10 16:08:24 UTC
+++ src/rw-touch.c
@@ -10,7 +10,7 @@
 char const* PROG="rw-touch";
 
 int main(int argc, char** argv) {
-  tain_t t;
+  tain t;
   struct timeval tv[2];
   if (argc<3) DIE_USAGE(" stamp filename [program...]");
   rw_scan(&t, argv[1]);
