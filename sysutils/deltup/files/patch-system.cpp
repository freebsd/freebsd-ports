--- system.cpp.orig	2007-03-25 01:45:52.000000000 +0300
+++ system.cpp	2013-10-06 17:14:02.000000000 +0400
@@ -11,7 +11,8 @@
  *
  * Author: John Whitney <jjw@deltup.org>
  */
- 
+
+#include <stdlib.h> 
 #include <sys/signal.h>
 #include <string>
 #include <vector>
@@ -19,7 +20,7 @@
 using namespace std;
 #include "file.h"
 #include "bpatch.h"
-
+#include <sys/wait.h>
 #include "filetypes.h"
 
 bool verbose = false;
