--- ./chrome/common/chrome_paths.h.orig	2014-04-30 22:42:24.000000000 +0200
+++ ./chrome/common/chrome_paths.h	2014-05-04 14:38:46.000000000 +0200
@@ -111,7 +111,7 @@
                                    // files to be installed when managed user
                                    // session starts.
 
-#if defined(OS_LINUX) || (defined(OS_MACOSX) && !defined(OS_IOS))
+#if defined(OS_LINUX) || defined(OS_FREEBSD) || (defined(OS_MACOSX) && !defined(OS_IOS))
   DIR_NATIVE_MESSAGING,         // System directory where native messaging host
                                 // manifest files are stored.
   DIR_USER_NATIVE_MESSAGING,    // Directory with Native Messaging Hosts
