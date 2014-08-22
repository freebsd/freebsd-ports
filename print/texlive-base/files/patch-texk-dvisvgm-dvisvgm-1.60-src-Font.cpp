--- texk/dvisvgm/dvisvgm-1.6/src/Font.cpp.orig	2014-04-13 22:09:23.000000000 +0900
+++ texk/dvisvgm/dvisvgm-1.6/src/Font.cpp	2014-08-20 23:41:16.000000000 +0900
@@ -19,6 +19,7 @@
 *************************************************************************/
 
 #include <config.h>
+#include <sys/time.h>
 #include <cstdlib>
 #include <iostream>
 #include <fstream>
