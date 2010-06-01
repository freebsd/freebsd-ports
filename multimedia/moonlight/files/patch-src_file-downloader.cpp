
$FreeBSD$

--- src/file-downloader.cpp.orig
+++ src/file-downloader.cpp
@@ -17,6 +17,9 @@
 #include <glib/gstdio.h>
 #include <fcntl.h>
 #include <errno.h>
+#ifdef __FreeBSD__
+#include <unistd.h>
+#endif
 
 #include "file-downloader.h"
 #include "zip/unzip.h"
