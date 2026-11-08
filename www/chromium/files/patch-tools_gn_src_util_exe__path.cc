--- tools/gn/src/util/exe_path.cc.orig	2026-09-25 15:26:43 UTC
+++ tools/gn/src/util/exe_path.cc
@@ -15,7 +15,7 @@
 #include <windows.h>
 
 #include "base/win/win_util.h"
-#elif defined(OS_FREEBSD) || defined(OS_NETBSD)
+#elif defined(OS_FREEBSD) || defined(OS_NETBSD) || defined(OS_OPENBSD)
 #include <limits.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
@@ -26,6 +26,10 @@
 #include <stdlib.h>
 #endif
 
+#if defined(OS_OPENBSD)
+#include <sys/param.h>
+#endif
+
 #if defined(OS_MACOSX)
 
 base::FilePath GetExePath() {
@@ -102,6 +106,20 @@ base::FilePath GetExePath() {
     return base::FilePath();
   }
   return base::FilePath(raw);
+}
+
+#elif defined(OS_OPENBSD)
+
+base::FilePath GetExePath() {
+#if (OpenBSD >= 202610)
+  char execpath[PATH_MAX];
+  if (getexecpath(execpath, sizeof(execpath)) != 0)
+    return base::FilePath();
+
+  return base::FilePath(execpath);
+#else
+  return base::FilePath();
+#endif
 }
 
 #elif defined(OS_ZOS)
