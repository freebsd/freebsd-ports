--- third_party/crashpad/crashpad/util/posix/signals.cc.orig	2018-07-19 19:52:18.124704000 +0200
+++ third_party/crashpad/crashpad/util/posix/signals.cc	2018-07-19 19:53:53.609005000 +0200
@@ -44,7 +44,7 @@
 #if defined(SIGEMT)
     SIGEMT,
 #endif  // defined(SIGEMT)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     SIGXCPU,
     SIGXFSZ,
 #endif  // defined(OS_LINUX)
@@ -84,7 +84,7 @@
     SIGXCPU,
     SIGXFSZ,
 #endif  // defined(OS_MACOSX)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     SIGIO,
 #endif  // defined(OS_LINUX)
 };
@@ -214,8 +214,12 @@
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
