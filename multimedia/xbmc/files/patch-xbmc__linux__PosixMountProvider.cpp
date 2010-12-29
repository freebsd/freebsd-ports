--- ./xbmc/linux/PosixMountProvider.cpp.orig	2010-01-09 00:47:11.000000000 +0100
+++ ./xbmc/linux/PosixMountProvider.cpp	2010-12-01 12:17:34.257919126 +0100
@@ -98,6 +98,8 @@
 
 #ifdef __APPLE__
   FILE* pipe = popen("df -hT ufs,cd9660,hfs,udf", "r");
+#elif defined(__FreeBSD__)  
+  FILE* pipe = popen("df -h -t ufs,cd9660,hfs,udf,zfs", "r");
 #else
   FILE* pipe = popen("df -hx tmpfs", "r");
 #endif
