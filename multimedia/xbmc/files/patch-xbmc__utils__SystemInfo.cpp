--- ./xbmc/utils/SystemInfo.cpp.orig	2010-06-16 03:13:48.000000000 +0200
+++ ./xbmc/utils/SystemInfo.cpp	2010-12-01 12:17:34.279062075 +0100
@@ -607,7 +607,7 @@
   return strRet;
 }
 
-#if defined(_LINUX) && !defined(__APPLE__)
+#if defined(_LINUX) && !defined(__APPLE__) && !defined(__FreeBSD__)
 CStdString CSysInfo::GetLinuxDistro()
 {
   static const char* release_file[] = { "/etc/debian_version",
@@ -674,6 +674,9 @@
 #elif defined(__APPLE__)
   result += "Mac OS X; ";
   result += GetUnameVersion();
+#elif defined(__FreeBSD__)
+  result += "FreeBSD; ";
+  result += GetUnameVersion();
 #elif defined(_LINUX)
   result += "Linux; ";
   result += GetLinuxDistro();
