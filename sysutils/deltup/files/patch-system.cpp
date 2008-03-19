--- system.cpp.orig	2007-03-25 04:45:52.000000000 +0600
+++ system.cpp		2008-03-08 22:51:00.000000000 +0500
@@ -19,7 +19,7 @@
 using namespace std;
 #include "file.h"
 #include "bpatch.h"
-
+#include <sys/wait.h>
 #include "filetypes.h"
 
 bool verbose = false;
