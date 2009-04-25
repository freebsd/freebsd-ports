--- ./libs/libmythfreemheg/Programs.cpp.orig	2007-03-29 15:44:23.000000000 -0400
+++ ./libs/libmythfreemheg/Programs.cpp	2009-04-22 21:05:20.000000000 -0400
@@ -32,6 +32,10 @@
 #include <sys/timeb.h>
 #include <time.h>
 
+#ifdef __FreeBSD__
+#include <sys/time.h>
+#endif
+
 #include "../../config.h"
 
 /*
