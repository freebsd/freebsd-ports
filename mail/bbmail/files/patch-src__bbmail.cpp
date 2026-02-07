--- src/bbmail.cpp.orig
+++ src/bbmail.cpp
@@ -22,13 +22,14 @@
 #include "bbmail.h"
 #include "config.h"
 #include <string>
+#include <cstdlib>
+#include <cmath>
 
 extern "C" {
 #include <utime.h>
 #include <dirent.h>
 #include <X11/cursorfont.h>
 #include <sys/stat.h>
-#include <math.h>
 }
 
 #include "EWMH.hh"
