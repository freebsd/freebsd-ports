--- content/public/app/content_main_delegate.h.orig	2021-09-14 01:51:56 UTC
+++ content/public/app/content_main_delegate.h
@@ -53,7 +53,7 @@ class CONTENT_EXPORT ContentMainDelegate {
   // Called right before the process exits.
   virtual void ProcessExiting(const std::string& process_type) {}
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Tells the embedder that the zygote process is starting, and allows it to
   // specify one or more zygote delegates if it wishes by storing them in
   // |*delegates|.
@@ -62,7 +62,7 @@ class CONTENT_EXPORT ContentMainDelegate {
 
   // Called every time the zygote process forks.
   virtual void ZygoteForked() {}
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   // Fatal errors during initialization are reported by this function, so that
   // the embedder can implement graceful exit by displaying some message and
