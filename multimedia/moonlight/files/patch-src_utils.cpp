
$FreeBSD$

--- src/utils.cpp.orig
+++ src/utils.cpp
@@ -16,6 +16,9 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <stdlib.h>
+#ifdef __FreeBSD__
+#include <unistd.h>
+#endif
 
 #include "utils.h"
 #include "application.h"
