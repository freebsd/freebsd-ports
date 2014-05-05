--- src/CTPP2FileSourceLoader.cpp.orig	2012-08-02 11:22:44.000000000 +0400
+++ src/CTPP2FileSourceLoader.cpp	2014-05-02 18:06:25.511300597 +0400
@@ -38,6 +38,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 
 #ifdef WIN32
     #include <direct.h> /* getcwd */
