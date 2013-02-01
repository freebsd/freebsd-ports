--- Modules/SharedSource/OVCINInfo.cpp.orig	2012-05-06 21:47:52.000000000 +0800
+++ Modules/SharedSource/OVCINInfo.cpp	2012-05-06 22:02:40.000000000 +0800
@@ -67,7 +67,7 @@
 }
 
 #ifndef WIN32
-    #ifdef __linux__
+    #if defined (__linux__) || defined (__FreeBSD__)
        int CLFileSelect(const struct dirent *entry)
     #else
        int CLFileSelect(struct dirent *entry)
