--- texk/dvisvgm/dvisvgm-src/src/FileFinder.cpp.orig	2023-01-20 01:55:04 UTC
+++ texk/dvisvgm/dvisvgm-src/src/FileFinder.cpp
@@ -31,6 +31,7 @@
 	#endif
 #endif
 
+#include <sys/time.h>
 #include <cstdlib>
 #include <fstream>
 #include <map>
