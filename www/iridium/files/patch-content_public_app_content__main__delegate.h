--- content/public/app/content_main_delegate.h.orig	2020-03-16 18:40:32 UTC
+++ content/public/app/content_main_delegate.h
@@ -72,7 +72,7 @@ class CONTENT_EXPORT ContentMainDelegate {
   // want it at all.
   virtual bool DelaySandboxInitialization(const std::string& process_type);
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Tells the embedder that the zygote process is starting, and allows it to
   // specify one or more zygote delegates if it wishes by storing them in
   // |*delegates|.
@@ -82,7 +82,7 @@ class CONTENT_EXPORT ContentMainDelegate {
 
   // Called every time the zygote process forks.
   virtual void ZygoteForked() {}
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   // Fatal errors during initialization are reported by this function, so that
   // the embedder can implement graceful exit by displaying some message and
