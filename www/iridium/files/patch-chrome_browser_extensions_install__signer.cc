--- chrome/browser/extensions/install_signer.cc.orig	2020-03-16 18:39:44 UTC
+++ chrome/browser/extensions/install_signer.cc
@@ -294,13 +294,13 @@ void LogRequestStartHistograms() {
   DCHECK(g_single_thread_checker.Get().CalledOnValidThread());
 
   // Process::Current().CreationTime is only defined on some platforms.
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   const base::Time process_creation_time =
       base::Process::Current().CreationTime();
   UMA_HISTOGRAM_COUNTS_1M(
       "ExtensionInstallSigner.UptimeAtTimeOfRequest",
       (base::Time::Now() - process_creation_time).InSeconds());
-#endif  // defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
   base::TimeDelta delta;
   base::TimeTicks now = base::TimeTicks::Now();
