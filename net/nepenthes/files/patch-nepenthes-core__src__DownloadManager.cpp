--- nepenthes-core/src/DownloadManager.cpp.orig
+++ nepenthes-core/src/DownloadManager.cpp
@@ -27,6 +27,9 @@
 
 /* $Id: DownloadManager.cpp 1548 2008-02-14 11:18:18Z common $ */
 
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
 #include <string>
 #include <sys/param.h>
 
