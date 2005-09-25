--- src/bin/ewl_test.h.orig	Mon Jul 11 08:14:53 2005
+++ src/bin/ewl_test.h	Sun Sep 25 11:25:52 2005
@@ -1,5 +1,15 @@
 #include "Ewl.h"
-#include <ewl-config.h>
+#include <ewl_macros.h>
+#ifdef HAVE_CONFIG_H
+#include "ewl-config.h"
+#endif
+
+#include <stdlib.h>
+#include <stdio.h>
+#include <string.h>
+#include <dirent.h>
+#include <limits.h>
+#include <sys/stat.h>
 
 #if HAVE___ATTRIBUTE__
 #define __UNUSED__ __attribute__((unused))
