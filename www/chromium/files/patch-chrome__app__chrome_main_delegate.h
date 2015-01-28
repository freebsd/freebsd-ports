--- chrome/app/chrome_main_delegate.h.orig	2015-01-21 20:05:38 UTC
+++ chrome/app/chrome_main_delegate.h
@@ -37,7 +37,7 @@
       const std::string& process_type) override;
   bool ShouldSendMachPort(const std::string& process_type) override;
   bool DelaySandboxInitialization(const std::string& process_type) override;
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   void ZygoteStarting(
       ScopedVector<content::ZygoteForkDelegate>* delegates) override;
   void ZygoteForked() override;
