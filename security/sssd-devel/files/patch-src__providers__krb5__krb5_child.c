--- src/providers/krb5/krb5_child.c.orig	2023-05-05 08:11:07 UTC
+++ src/providers/krb5/krb5_child.c
@@ -28,7 +28,6 @@
 #include <fcntl.h>
 #include <ctype.h>
 #include <popt.h>
-#include <sys/prctl.h>
 
 #include <security/pam_modules.h>
 
@@ -4070,8 +4069,6 @@ int main(int argc, const char *argv[])
     }
 
     poptFreeContext(pc);
-
-    prctl(PR_SET_DUMPABLE, (dumpable == 0) ? 0 : 1);
 
     debug_prg_name = talloc_asprintf(NULL, "krb5_child[%d]", getpid());
     if (!debug_prg_name) {
