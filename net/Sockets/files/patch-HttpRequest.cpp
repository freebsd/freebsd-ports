--- HttpRequest.cpp.orig	2011-07-17 10:06:09.000000000 +0200
+++ HttpRequest.cpp	2012-12-29 14:17:14.000000000 +0100
@@ -44,6 +44,8 @@
 namespace SOCKETS_NAMESPACE {
 #endif
 
+extern char**environ;
+
 #ifdef _DEBUG
 #define DEB(x) x; fflush(stderr);
 #else
