--- content/public/common/child_process_host.h.orig	2017-06-05 19:03:07 UTC
+++ content/public/common/child_process_host.h
@@ -46,7 +46,7 @@ class CONTENT_EXPORT ChildProcessHost : public IPC::Se
     // No special behavior requested.
     CHILD_NORMAL = 0,
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Indicates that the child execed after forking may be execced from
     // /proc/self/exe rather than using the "real" app path. This prevents
     // autoupdate from confusing us if it changes the file out from under us.
@@ -55,7 +55,7 @@ class CONTENT_EXPORT ChildProcessHost : public IPC::Se
     // gdb). In this case, you'd use GetChildPath to get the real executable
     // file name, and then prepend the GDB command to the command line.
     CHILD_ALLOW_SELF = 1 << 0,
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   };
 
   // Returns the pathname to be used for a child process.  If a subprocess
