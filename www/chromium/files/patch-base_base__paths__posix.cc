--- base/base_paths_posix.cc.orig	2026-09-25 15:26:43 UTC
+++ base/base_paths_posix.cc
@@ -26,7 +26,7 @@
 #include "base/process/process_metrics.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_BSD)
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #elif BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_AIX)
@@ -47,8 +47,7 @@ bool PathProviderPosix(int key, FilePath* result) {
       *result = bin_dir;
       return true;
 #elif BUILDFLAG(IS_FREEBSD)
-      int name[] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
-      std::optional<std::string> bin_dir = StringSysctl(name, std::size(name));
+      std::optional<std::string> bin_dir = StringSysctl({ CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 });
       if (!bin_dir.has_value() || bin_dir.value().length() <= 1) {
         NOTREACHED() << "Unable to resolve path.";
       }
@@ -61,7 +60,14 @@ bool PathProviderPosix(int key, FilePath* result) {
       }
       *result = FilePath(bin_dir);
       return true;
-#elif BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_AIX)
+#elif BUILDFLAG(IS_OPENBSD) && (OpenBSD >= 202610)
+      char execpath[PATH_MAX];
+      if (getexecpath(execpath, sizeof(execpath)) != 0) {
+        NOTREACHED() << "Unable to resolve path.";
+      }
+      *result = FilePath(execpath);
+      return true;
+#elif BUILDFLAG(IS_AIX) || BUILDFLAG(IS_OPENBSD)
       // There is currently no way to get the executable path on OpenBSD
       char* cpath;
       if ((cpath = getenv("CHROME_EXE_PATH")) != NULL) {
