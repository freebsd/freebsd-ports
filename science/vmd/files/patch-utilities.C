--- src/utilities.C.orig	Sat Jan 22 16:15:24 2005
+++ src/utilities.C	Sat Jan 22 16:15:45 2005
@@ -396,7 +396,7 @@
     return stringdup("Windows User");
   }
 #else
-#if defined(ARCH_FREEBSD) || defined(__APPLE__) || defined(__linux)
+#if defined(ARCH_FREEBSD) || defined(ARCH_FREEBSDAMD64) || defined(__APPLE__) || defined(__linux)
   return stringdup(getlogin());
 #else
   return stringdup(cuserid(NULL));
