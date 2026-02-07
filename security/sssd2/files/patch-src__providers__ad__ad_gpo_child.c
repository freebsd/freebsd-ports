--- src/providers/ad/ad_gpo_child.c.orig	2023-05-05 08:11:07 UTC
+++ src/providers/ad/ad_gpo_child.c
@@ -26,7 +26,6 @@
 #include <ctype.h>
 #include <unistd.h>
 #include <popt.h>
-#include <sys/prctl.h>
 #include <libsmbclient.h>
 #include <security/pam_modules.h>
 
@@ -699,8 +698,6 @@ main(int argc, const char *argv[])
     }
 
     poptFreeContext(pc);
-
-    prctl(PR_SET_DUMPABLE, (dumpable == 0) ? 0 : 1);
 
     debug_prg_name = talloc_asprintf(NULL, "gpo_child[%d]", getpid());
     if (debug_prg_name == NULL) {
