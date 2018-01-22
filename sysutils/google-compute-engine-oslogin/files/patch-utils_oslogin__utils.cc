--- utils/oslogin_utils.cc.orig	2017-12-13 23:47:59 UTC
+++ utils/oslogin_utils.cc
@@ -218,7 +218,14 @@ bool ValidatePasswd(struct passwd* resul
     }
   }
   if (strlen(result->pw_shell) == 0) {
-    if (!buf->AppendString("/bin/bash", &result->pw_shell, errnop)) {
+    if (!buf->AppendString("/bin/sh", &result->pw_shell, errnop)) {
+      return false;
+    }
+  }
+
+  // If shell is set to /bin/bash, fallback to /bin/sh
+  if (strcmp(result->pw_shell, "/bin/bash") == 0 ) {
+    if (!buf->AppendString("/bin/sh", &result->pw_shell, errnop)) {
       return false;
     }
   }
