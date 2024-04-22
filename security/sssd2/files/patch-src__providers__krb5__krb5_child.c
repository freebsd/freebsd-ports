--- src/providers/krb5/krb5_child.c.orig	2024-01-12 12:05:40 UTC
+++ src/providers/krb5/krb5_child.c
@@ -28,7 +28,6 @@
 #include <fcntl.h>
 #include <ctype.h>
 #include <popt.h>
-#include <sys/prctl.h>
 
 #include <security/pam_modules.h>
 
@@ -4090,8 +4089,6 @@ int main(int argc, const char *argv[])
     }
 
     poptFreeContext(pc);
-
-    prctl(PR_SET_DUMPABLE, (dumpable == 0) ? 0 : 1);
 
     debug_prg_name = talloc_asprintf(NULL, "krb5_child[%d]", getpid());
     if (!debug_prg_name) {
