--- src/ucs/config/parser.c.orig	2026-09-09 02:32:02 UTC
+++ src/ucs/config/parser.c
@@ -27,6 +27,7 @@
 #include <ctype.h>
 #include <libgen.h>
 #include <regex.h>
+#include <signal.h>
 
 
 /* width of titles in docstring */
@@ -697,6 +698,8 @@ int ucs_config_sscanf_signo(const char *buf, void *des
 int ucs_config_sscanf_signo(const char *buf, void *dest, const void *arg)
 {
     char *endptr;
+    const char *name;
+    const char *name_nosig;
     int signo;
 
     signo = strtol(buf, &endptr, 10);
@@ -705,11 +708,31 @@ int ucs_config_sscanf_signo(const char *buf, void *des
         return 1;
     }
 
-    if (!strncmp(buf, "SIG", 3)) {
-        buf += 3;
+    name = buf;
+    if (!strncasecmp(name, "SIG", 3)) {
+        name_nosig = name + 3;
+    } else {
+        name_nosig = name;
     }
 
-    return ucs_config_sscanf_enum(buf, dest, ucs_signal_names);
+#if defined(__FreeBSD__)
+    for (signo = 1; signo < NSIG; ++signo) {
+        if ((sys_signame[signo] != NULL) &&
+            !strcasecmp(name_nosig, sys_signame[signo])) {
+            *(int*)dest = signo;
+            return 1;
+        }
+    }
+#endif
+
+    if (ucs_config_sscanf_enum(name_nosig, dest, ucs_signal_names)) {
+        return 1;
+    }
+    if (name_nosig != name) {
+        return ucs_config_sscanf_enum(name, dest, ucs_signal_names);
+    }
+
+    return 0;
 }
 
 int ucs_config_sprintf_signo(char *buf, size_t max,
