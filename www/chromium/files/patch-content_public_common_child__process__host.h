--- content/public/common/child_process_host.h.orig	2020-03-03 18:53:07 UTC
+++ content/public/common/child_process_host.h
@@ -80,7 +80,7 @@ class CONTENT_EXPORT ChildProcessHost : public IPC::Se
     // No special behavior requested.
     CHILD_NORMAL = 0,
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Indicates that the child execed after forking may be execced from
     // /proc/self/exe rather than using the "real" app path. This prevents
     // autoupdate from confusing us if it changes the file out from under us.
