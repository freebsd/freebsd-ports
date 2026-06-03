--- src/rw-touch.c.orig	2021-04-23 23:22:53 UTC
+++ src/rw-touch.c
@@ -2,6 +2,7 @@
 #include <sys/time.h>
 #include <errno.h>
 
+#include <skalibs/exec.h>
 #include <skalibs/stddjb.h>
 #include "prjlibs-include/constants.h"
 #include "prjlibs-include/diewarn.h"
@@ -10,7 +11,7 @@ int main(int argc, char** argv) {
 char const* PROG="rw-touch";
 
 int main(int argc, char** argv) {
-  tain_t t;
+  tain t;
   struct timeval tv[2];
   if (argc<3) DIE_USAGE(" stamp filename [program...]");
   rw_scan(&t, argv[1]);
