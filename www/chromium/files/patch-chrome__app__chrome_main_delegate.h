--- ./chrome/app/chrome_main_delegate.h.orig	2014-04-24 22:34:55.000000000 +0200
+++ ./chrome/app/chrome_main_delegate.h	2014-04-24 23:23:42.000000000 +0200
@@ -31,7 +31,7 @@
   virtual bool ShouldSendMachPort(const std::string& process_type) OVERRIDE;
   virtual bool DelaySandboxInitialization(
       const std::string& process_type) OVERRIDE;
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   virtual content::ZygoteForkDelegate* ZygoteStarting() OVERRIDE;
   virtual void ZygoteForked() OVERRIDE;
 #endif
