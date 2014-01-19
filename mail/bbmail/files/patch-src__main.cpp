--- src/main.cpp.orig
+++ src/main.cpp
@@ -22,6 +22,7 @@
 #include "bbmail.h"
 #include "main.h"
 #include "config.h"
+#include <cstdlib>
 
 Configuration::Configuration(int iargc, char **iargv)
 {
