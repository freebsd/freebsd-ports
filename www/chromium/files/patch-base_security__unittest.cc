--- base/security_unittest.cc.orig	2020-07-07 21:57:30 UTC
+++ base/security_unittest.cc
@@ -59,7 +59,7 @@ NOINLINE Type HideValueFromCompiler(volatile Type valu
 // FAILS_ is too clunky.
 void OverflowTestsSoftExpectTrue(bool overflow_detected) {
   if (!overflow_detected) {
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_NACL)
     // Sadly, on Linux, Android, and OSX we don't have a good story yet. Don't
     // fail the test, but report.
     printf("Platform has overflow: %s\n",
