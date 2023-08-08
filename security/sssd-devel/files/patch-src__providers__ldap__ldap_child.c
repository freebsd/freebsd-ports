--- src/providers/ldap/ldap_child.c.orig	2023-05-05 08:11:07 UTC
+++ src/providers/ldap/ldap_child.c
@@ -23,11 +23,11 @@
 */
 
 #include <sys/types.h>
+#include <sys/param.h>
 #include <unistd.h>
 #include <sys/stat.h>
 #include <signal.h>
 #include <popt.h>
-#include <sys/prctl.h>
 
 #include "util/util.h"
 #include "util/sss_krb5.h"
@@ -337,7 +337,7 @@ static krb5_error_code ldap_child_get_tgt_sync(TALLOC_
             full_princ = talloc_strdup(tmp_ctx, princ_str);
         }
     } else {
-        char hostname[HOST_NAME_MAX + 1];
+        char hostname[MAXHOSTNAMELEN + 1];
 
         ret = gethostname(hostname, sizeof(hostname));
         if (ret == -1) {
@@ -346,7 +346,7 @@ static krb5_error_code ldap_child_get_tgt_sync(TALLOC_
                                          errno, strerror(errno));
             goto done;
         }
-        hostname[HOST_NAME_MAX] = '\0';
+        hostname[MAXHOSTNAMELEN] = '\0';
 
         DEBUG(SSSDBG_TRACE_LIBS, "got hostname: [%s]\n", hostname);
 
@@ -660,8 +660,6 @@ int main(int argc, const char *argv[])
     }
 
     poptFreeContext(pc);
-
-    prctl(PR_SET_DUMPABLE, (dumpable == 0) ? 0 : 1);
 
     debug_prg_name = talloc_asprintf(NULL, "ldap_child[%d]", getpid());
     if (!debug_prg_name) {
