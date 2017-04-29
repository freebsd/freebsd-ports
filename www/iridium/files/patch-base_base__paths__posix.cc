--- base/base_paths_posix.cc.orig	2017-04-19 19:06:28 UTC
+++ base/base_paths_posix.cc
@@ -67,13 +67,13 @@ bool PathProviderPosix(int key, FilePath
       }
       *result = FilePath(bin_dir);
       return true;
-#elif defined(OS_OPENBSD)
-      // There is currently no way to get the executable path on OpenBSD
+#elif defined(OS_BSD)
+      // There is currently no way to get the executable path on FreeBSD
       char* cpath;
-      if ((cpath = getenv("CHROME_EXE_PATH")) != NULL)
+      if ((cpath = getenv("IRIDIUM_EXE_PATH")) != NULL)
         *result = FilePath(cpath);
       else
-        *result = FilePath("/usr/local/chrome/chrome");
+        *result = FilePath("/usr/local/iridium/iridium");
       return true;
 #endif
     }
