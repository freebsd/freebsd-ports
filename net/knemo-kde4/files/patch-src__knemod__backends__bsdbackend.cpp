--- ./src/knemod/backends/bsdbackend.cpp.orig	2010-08-28 03:59:37.000000000 +0400
+++ ./src/knemod/backends/bsdbackend.cpp	2010-10-03 18:39:22.262318381 +0400
@@ -52,6 +52,7 @@
 #include <KLocale>
 #include <kio/global.h>
 #include <stdio.h>
+#include <unistd.h>
 
 #ifdef __GLIBC__
 #include <unistd.h>
