--- client/hostinfo_unix.cpp.orig	2013-12-20 14:28:08.000000000 -0600
+++ client/hostinfo_unix.cpp	2014-04-16 17:07:56.996236131 -0500
@@ -1213,6 +1213,8 @@
 
 #if LINUX_LIKE_SYSTEM
     safe_strcpy(path, "/usr/lib/virtualbox/VBoxManage");
+#elif defined( __FreeBSD__)
+    safe_strcpy(path, "@PREFIX@/lib/virtualbox/VBoxManage");
 #elif defined( __APPLE__)
     FSRef theFSRef;
     OSStatus status = noErr;
@@ -1231,7 +1233,7 @@
 #endif
 
     if (boinc_file_exists(path)) {
-#if LINUX_LIKE_SYSTEM
+#if LINUX_LIKE_SYSTEM || defined( __FreeBSD__)
         if (access(path, X_OK)) {
             return 0;
         }
