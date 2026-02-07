--- status.cc	2004-05-29 16:00:06.000000000 -0700
+++ status.cc	2008-03-02 23:03:02.000000000 -0800
@@ -20,6 +20,7 @@
 #include "server.h"
 #include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 
 static int errorflags=0, warnflags=0, okflags=0;
 
