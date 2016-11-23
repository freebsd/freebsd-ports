--- ./content/public/common/child_process_host.h.orig	2016-07-20 22:03:24.000000000 +0300
+++ ./content/public/common/child_process_host.h	2016-08-18 02:52:30.173927000 +0300
@@ -50,7 +50,7 @@
     // No special behavior requested.
     CHILD_NORMAL = 0,
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Indicates that the child execed after forking may be execced from
     // /proc/self/exe rather than using the "real" app path. This prevents
     // autoupdate from confusing us if it changes the file out from under us.
@@ -59,7 +59,7 @@
     // gdb). In this case, you'd use GetChildPath to get the real executable
     // file name, and then prepend the GDB command to the command line.
     CHILD_ALLOW_SELF = 1 << 0,
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   };
 
   // Returns the pathname to be used for a child process.  If a subprocess
