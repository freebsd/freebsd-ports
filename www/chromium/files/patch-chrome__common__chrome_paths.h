--- ./chrome/common/chrome_paths.h.orig	2014-08-20 21:01:56.000000000 +0200
+++ ./chrome/common/chrome_paths.h	2014-08-22 15:06:25.000000000 +0200
@@ -115,7 +115,7 @@
   DIR_SUPERVISED_USERS_DEFAULT_APPS,  // Directory where installer places .crx
                                       // files to be installed when managed user
                                       // session starts.
-#if defined(OS_LINUX) || (defined(OS_MACOSX) && !defined(OS_IOS))
+#if defined(OS_LINUX) || defined(OS_BSD) || (defined(OS_MACOSX) && !defined(OS_IOS))
   DIR_NATIVE_MESSAGING,         // System directory where native messaging host
                                 // manifest files are stored.
   DIR_USER_NATIVE_MESSAGING,    // Directory with Native Messaging Hosts
