--- src/DiskCache.cxx.orig	2013-10-29 00:12:10.513674000 +0000
+++ src/DiskCache.cxx
@@ -25,6 +25,7 @@
 #include <sys/stat.h>
 #include <cerrno>
 #include <cstring>
+#include <unistd.h>
 
 #include "DiskCache.H"
 #include "globals.H"
