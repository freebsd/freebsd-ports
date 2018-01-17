--- src/3rdparty/chromium/content/public/common/child_process_host.h.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/public/common/child_process_host.h
@@ -53,7 +53,7 @@ class CONTENT_EXPORT ChildProcessHost : 
     // No special behavior requested.
     CHILD_NORMAL = 0,
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Indicates that the child execed after forking may be execced from
     // /proc/self/exe rather than using the "real" app path. This prevents
     // autoupdate from confusing us if it changes the file out from under us.
@@ -62,7 +62,7 @@ class CONTENT_EXPORT ChildProcessHost : 
     // gdb). In this case, you'd use GetChildPath to get the real executable
     // file name, and then prepend the GDB command to the command line.
     CHILD_ALLOW_SELF = 1 << 0,
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   };
 
   // Returns the pathname to be used for a child process.  If a subprocess
