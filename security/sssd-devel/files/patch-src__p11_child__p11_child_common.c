--- src/p11_child/p11_child_common.c.orig	2023-05-05 08:11:07 UTC
+++ src/p11_child/p11_child_common.c
@@ -27,7 +27,6 @@
 #include <stdlib.h>
 #include <string.h>
 #include <popt.h>
-#include <sys/prctl.h>
 
 #include "util/util.h"
 #include "util/child_common.h"
@@ -305,8 +304,6 @@ int main(int argc, const char *argv[])
     }
 
     poptFreeContext(pc);
-
-    prctl(PR_SET_DUMPABLE, (dumpable == 0) ? 0 : 1);
 
     debug_prg_name = talloc_asprintf(NULL, "p11_child[%d]", getpid());
     if (debug_prg_name == NULL) {
