--- src/CTPP2FileSourceLoader.cpp.orig	2013-11-16 14:26:59.000000000 +0100
+++ src/CTPP2FileSourceLoader.cpp	2013-11-16 14:27:17.000000000 +0100
@@ -38,6 +38,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 
 #ifdef WIN32
     #include <direct.h> /* getcwd */
