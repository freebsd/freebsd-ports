--- chrome/app/chrome_main_delegate.h.orig	2014-10-02 17:18:53 UTC
+++ chrome/app/chrome_main_delegate.h
@@ -38,7 +38,7 @@
   virtual bool ShouldSendMachPort(const std::string& process_type) OVERRIDE;
   virtual bool DelaySandboxInitialization(
       const std::string& process_type) OVERRIDE;
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   virtual void ZygoteStarting(
       ScopedVector<content::ZygoteForkDelegate>* delegates) OVERRIDE;
   virtual void ZygoteForked() OVERRIDE;
