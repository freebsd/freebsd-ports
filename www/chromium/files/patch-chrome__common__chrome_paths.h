--- chrome/common/chrome_paths.h.orig	2014-10-10 08:54:11 UTC
+++ chrome/common/chrome_paths.h
@@ -112,7 +112,7 @@
   DIR_SUPERVISED_USERS_DEFAULT_APPS,  // Directory where installer places .crx
                                       // files to be installed when managed user
                                       // session starts.
-#if defined(OS_LINUX) || (defined(OS_MACOSX) && !defined(OS_IOS))
+#if defined(OS_LINUX) || defined(OS_BSD) || (defined(OS_MACOSX) && !defined(OS_IOS))
   DIR_NATIVE_MESSAGING,         // System directory where native messaging host
                                 // manifest files are stored.
   DIR_USER_NATIVE_MESSAGING,    // Directory with Native Messaging Hosts
