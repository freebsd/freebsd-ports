--- apps/xmlrpc2di/xmlrpc++/src/base64.h.orig	2019-12-06 20:43:40.279650000 -0800
+++ apps/xmlrpc2di/xmlrpc++/src/base64.h	2019-12-06 20:44:03.636359000 -0800
@@ -9,9 +9,9 @@
 #if !defined(__BASE64_H_INCLUDED__)
 #define __BASE64_H_INCLUDED__ 1
 
-#if defined __APPLE__ && defined __clang__
+#if !defined(__glibc__) && defined __clang__
 #include <ios>
-#endif // __APPLE__ && __clang__
+#endif // !__glibc__ && __clang__
 
 #ifndef MAKEDEPEND
 # include <iterator>
