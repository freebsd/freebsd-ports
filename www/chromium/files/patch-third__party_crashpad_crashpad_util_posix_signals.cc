--- third_party/crashpad/crashpad/util/posix/signals.cc.orig	2020-09-08 19:14:24 UTC
+++ third_party/crashpad/crashpad/util/posix/signals.cc
@@ -46,10 +46,10 @@ constexpr int kCrashSignals[] = {
 #if defined(SIGEMT)
     SIGEMT,
 #endif  // defined(SIGEMT)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     SIGXCPU,
     SIGXFSZ,
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 };
 
 // These are the non-core-generating but terminating signals.
@@ -86,9 +86,9 @@ constexpr int kTerminateSignals[] = {
     SIGXCPU,
     SIGXFSZ,
 #endif  // defined(OS_MACOSX)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     SIGIO,
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 };
 
 bool InstallHandlers(const std::vector<int>& signals,
@@ -225,8 +225,12 @@ bool Signals::WillSignalReraiseAutonomously(const sigi
          // remains. See 10.12.3 xnu-3789.41.3/bsd/kern/kern_sig.c
          // psignal_internal().
          (code > 0 &&
+#if defined(SI_ASYNCIO)
           code != SI_ASYNCIO &&
+#endif
+#if defined(SI_MESGQ)
           code != SI_MESGQ &&
+#endif
           code != SI_QUEUE &&
           code != SI_TIMER &&
           code != SI_USER &&
