--- base/security_unittest.cc.orig	2013-09-01 01:12:36.000000000 +0300
+++ base/security_unittest.cc	2013-09-01 01:13:35.000000000 +0300
@@ -161,7 +161,7 @@
 // FAILS_ is too clunky.
 void OverflowTestsSoftExpectTrue(bool overflow_detected) {
   if (!overflow_detected) {
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_NACL)
     // Sadly, on Linux, Android, and OSX we don't have a good story yet. Don't
     // fail the test, but report.
     printf("Platform has overflow: %s\n",
