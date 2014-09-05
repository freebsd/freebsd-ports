--- texk/dvisvgm/dvisvgm-1.6/src/Message.cpp.orig	2014-01-13 17:24:56.000000000 +0900
+++ texk/dvisvgm/dvisvgm-1.6/src/Message.cpp	2014-08-20 23:38:38.000000000 +0900
@@ -19,6 +19,7 @@
 *************************************************************************/
 
 #include <config.h>
+#include <sys/time.h>
 #include <cstdarg>
 #include <cstdlib>
 #include <cstring>
