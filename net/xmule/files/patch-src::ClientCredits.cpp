--- src/ClientCredits.cpp.orig	Tue May 27 15:25:08 2003
+++ src/ClientCredits.cpp	Tue May 27 15:25:19 2003
@@ -22,7 +22,7 @@
 #include "ClientCredits.h"
 #include "opcodes.h"
 #include <math.h>
-#include "/usr/include/time.h"
+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
