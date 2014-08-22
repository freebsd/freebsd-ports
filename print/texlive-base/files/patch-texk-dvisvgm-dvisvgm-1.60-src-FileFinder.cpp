--- texk/dvisvgm/dvisvgm-1.6/src/FileFinder.cpp.orig	2014-04-13 22:09:23.000000000 +0900
+++ texk/dvisvgm/dvisvgm-1.6/src/FileFinder.cpp	2014-08-20 23:34:37.000000000 +0900
@@ -34,6 +34,7 @@
 	#endif
 #endif
 
+#include <sys/time.h>
 #include <cstdlib>
 #include <fstream>
 #include <map>
