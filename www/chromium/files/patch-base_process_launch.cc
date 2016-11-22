--- base/process/launch.cc.orig	2016-10-06 04:02:08.000000000 +0300
+++ base/process/launch.cc	2016-10-13 04:27:47.136877000 +0300
@@ -15,7 +15,7 @@
 
 LaunchOptions LaunchOptionsForTest() {
   LaunchOptions options;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // To prevent accidental privilege sharing to an untrusted child, processes
   // are started with PR_SET_NO_NEW_PRIVS. Do not set that here, since this
   // new child will be used for testing only.
