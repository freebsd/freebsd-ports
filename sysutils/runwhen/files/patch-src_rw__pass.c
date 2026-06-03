--- src/rw_pass.c.orig	2021-04-23 23:20:53 UTC
+++ src/rw_pass.c
@@ -2,6 +2,7 @@
 #include <unistd.h>
 #include <errno.h>
 
+#include <skalibs/exec.h>
 #include <skalibs/stddjb.h>
 #include "prjlibs-include/constants.h"
 #include "prjlibs-include/diewarn.h"
@@ -9,7 +10,7 @@ extern char const* PROG;
 
 extern char const* PROG;
 
-void rw_pass(tain_t const* t, char** argv) {
+void rw_pass(tain const* t, char** argv) {
   char buf[2*TAIN_PACK+1];
 
   buf[tain_fmt(buf, t)]='\0';
