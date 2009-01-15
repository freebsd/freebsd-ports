--- libs/libmythfreemheg/Programs.cpp	2007-03-29 21:44:23.000000000 +0200
+++ libs/libmythfreemheg/Programs.cpp	2008-09-15 20:07:39.000000000 +0200
@@ -32,6 +32,10 @@
 #include <sys/timeb.h>
 #include <time.h>
 
+#ifdef __FreeBSD__
+#include <sys/time.h>
+#endif
+
 #include "../../config.h"
 
 /*
