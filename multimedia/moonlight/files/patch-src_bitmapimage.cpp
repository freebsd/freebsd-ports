
$FreeBSD$

--- src/bitmapimage.cpp.orig
+++ src/bitmapimage.cpp
@@ -16,6 +16,9 @@
 #include <glib/gstdio.h>
 #include <fcntl.h>
 #include <errno.h>
+#ifdef __FreeBSD__
+#include <unistd.h>
+#endif
 
 #include "application.h"
 #include "bitmapimage.h"
