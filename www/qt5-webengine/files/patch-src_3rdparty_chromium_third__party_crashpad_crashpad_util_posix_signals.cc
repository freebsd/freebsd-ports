--- src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/signals.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/signals.cc
@@ -228,8 +228,12 @@ bool Signals::WillSignalReraiseAutonomously(const sigi
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
