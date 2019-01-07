--- third_party/crashpad/crashpad/util/posix/symbolic_constants_posix.cc.orig	2018-12-03 21:17:55.000000000 +0100
+++ third_party/crashpad/crashpad/util/posix/symbolic_constants_posix.cc	2018-12-15 18:47:11.409455000 +0100
@@ -64,7 +64,7 @@
     "INFO",
     "USR1",
     "USR2",
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #if defined(ARCH_CPU_MIPS_FAMILY)
     "HUP",
     "INT",
@@ -135,7 +135,7 @@
 #endif  // defined(ARCH_CPU_MIPS_FAMILY)
 #endif
 };
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 // NSIG is 64 to account for real-time signals.
 static_assert(arraysize(kSignalNames) == 32, "kSignalNames length");
 #else
