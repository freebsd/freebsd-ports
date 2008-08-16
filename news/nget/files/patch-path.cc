--- path.cc	2004-05-29 16:00:06.000000000 -0700
+++ path.cc	2008-03-02 23:03:02.000000000 -0800
@@ -21,6 +21,7 @@
 #include <unistd.h>
 #include "log.h"
 #include "_fileconf.h"
+#include <string.h>
 
 #ifdef WIN32
 #include <ctype.h>
