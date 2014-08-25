--- ./chrome/app/chrome_main_delegate.h.orig	2014-08-20 21:01:26.000000000 +0200
+++ ./chrome/app/chrome_main_delegate.h	2014-08-22 15:06:24.000000000 +0200
@@ -38,7 +38,7 @@
   virtual bool ShouldSendMachPort(const std::string& process_type) OVERRIDE;
   virtual bool DelaySandboxInitialization(
       const std::string& process_type) OVERRIDE;
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   virtual void ZygoteStarting(
       ScopedVector<content::ZygoteForkDelegate>* delegates) OVERRIDE;
   virtual void ZygoteForked() OVERRIDE;
