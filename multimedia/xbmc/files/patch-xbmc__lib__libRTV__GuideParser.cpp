--- ./xbmc/lib/libRTV/GuideParser.cpp.orig	2010-02-12 00:47:51.000000000 +0100
+++ ./xbmc/lib/libRTV/GuideParser.cpp	2010-12-01 12:17:34.245845263 +0100
@@ -130,7 +130,7 @@
 #include <winbase.h>
 #endif
 
-#if (defined(__unix__) || defined(__APPLE__)) && !defined(__FreeBSD__)
+#if (defined(__unix__) || defined(__APPLE__))
 #include <netinet/in.h>
 #endif
 
