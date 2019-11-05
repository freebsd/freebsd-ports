--- content/public/app/content_main_delegate.h.orig	2019-09-16 14:44:25 UTC
+++ content/public/app/content_main_delegate.h
@@ -71,7 +71,7 @@ class CONTENT_EXPORT ContentMainDelegate {
   // want it at all.
   virtual bool DelaySandboxInitialization(const std::string& process_type);
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Tells the embedder that the zygote process is starting, and allows it to
   // specify one or more zygote delegates if it wishes by storing them in
   // |*delegates|.
@@ -81,7 +81,7 @@ class CONTENT_EXPORT ContentMainDelegate {
 
   // Called every time the zygote process forks.
   virtual void ZygoteForked() {}
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   // Allows the embedder to prevent locking the scheme registry. The scheme
   // registry is the list of URL schemes we recognize, with some additional
