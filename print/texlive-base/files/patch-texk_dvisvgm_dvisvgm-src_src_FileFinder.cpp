--- texk/dvisvgm/dvisvgm-src/src/FileFinder.cpp.orig	2022-01-29 15:54:24 UTC
+++ texk/dvisvgm/dvisvgm-src/src/FileFinder.cpp
@@ -32,6 +32,7 @@
 	#endif
 #endif
 
+#include <sys/time.h>
 #include <cstdlib>
 #include <fstream>
 #include <map>
