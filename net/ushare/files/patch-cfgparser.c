--- src/cfgparser.c.orig	Sun Nov 12 13:40:35 2006
+++ src/cfgparser.c	Sat Dec 23 03:33:22 2006
@@ -36,6 +36,11 @@
 #include "ushare.h"
 #include "trace.h"
 
+#if defined(__FreeBSD__)
+#include "strndup.h"
+#include "getline.h"
+#endif
+
 #define USHARE_DIR_DELIM ","
 
 static bool
