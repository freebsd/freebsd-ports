--- progs/demos/Lorenz/lorenz.c.orig	Mon Jan  3 11:24:15 2005
+++ progs/demos/Lorenz/lorenz.c	Sat Jun 11 14:06:07 2005
@@ -31,7 +31,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
-#include <GL/freeglut.h>
+#include "../../../include/GL/freeglut.h"
 #ifdef WIN32
 /* DUMP MEMORY LEAKS */
 #include <crtdbg.h>
