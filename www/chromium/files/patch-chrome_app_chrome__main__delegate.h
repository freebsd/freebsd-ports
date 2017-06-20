--- chrome/app/chrome_main_delegate.h.orig	2017-06-05 19:03:01 UTC
+++ chrome/app/chrome_main_delegate.h
@@ -42,7 +42,7 @@ class ChromeMainDelegate : public content::ContentMain
       const std::string& process_type) override;
   bool ShouldSendMachPort(const std::string& process_type) override;
   bool DelaySandboxInitialization(const std::string& process_type) override;
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   void ZygoteStarting(std::vector<std::unique_ptr<content::ZygoteForkDelegate>>*
                           delegates) override;
   void ZygoteForked() override;
