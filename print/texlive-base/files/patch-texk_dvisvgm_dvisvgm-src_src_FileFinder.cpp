--- texk/dvisvgm/dvisvgm-src/src/FileFinder.cpp.orig	2026-01-19 23:07:15 UTC
+++ texk/dvisvgm/dvisvgm-src/src/FileFinder.cpp
@@ -31,6 +31,7 @@
 	#endif
 #endif
 
+#include <sys/time.h>
 #include <cstdlib>
 #include <fstream>
 #include <map>
