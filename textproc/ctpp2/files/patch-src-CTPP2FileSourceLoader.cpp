--- src/CTPP2FileSourceLoader.cpp.orig	2012-08-02 07:22:44 UTC
+++ src/CTPP2FileSourceLoader.cpp
@@ -38,6 +38,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 
 #ifdef WIN32
     #include <direct.h> /* getcwd */
