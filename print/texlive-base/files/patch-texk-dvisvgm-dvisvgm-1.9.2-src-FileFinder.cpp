--- texk/dvisvgm/dvisvgm-1.9.2/src/FileFinder.cpp.orig	2015-03-02 08:48:21 UTC
+++ texk/dvisvgm/dvisvgm-1.9.2/src/FileFinder.cpp
@@ -34,6 +34,7 @@
 	#endif
 #endif
 
+#include <sys/time.h>
 #include <cstdlib>
 #include <fstream>
 #include <map>
