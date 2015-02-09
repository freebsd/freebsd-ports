--- ./base/security_unittest.cc.orig	2014-04-30 22:41:43.000000000 +0200
+++ ./base/security_unittest.cc	2014-05-04 14:38:46.000000000 +0200
@@ -159,7 +159,7 @@
 // FAILS_ is too clunky.
 void OverflowTestsSoftExpectTrue(bool overflow_detected) {
   if (!overflow_detected) {
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_NACL)
     // Sadly, on Linux, Android, and OSX we don't have a good story yet. Don't
     // fail the test, but report.
     printf("Platform has overflow: %s\n",
