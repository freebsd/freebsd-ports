--- humanunzip.cpp.orig
+++ humanunzip.cpp
@@ -22,6 +22,7 @@
 #include <fstream>
 #include <sstream>
 #include <vector>
+#include <unistd.h>
 #include <sys/stat.h>
 #include "humanzip.h"
 
