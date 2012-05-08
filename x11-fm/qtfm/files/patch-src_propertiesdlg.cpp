--- src/propertiesdlg.cpp~	2012-03-08 20:34:27.000000000 -0600
+++ src/propertiesdlg.cpp	2012-04-29 06:49:57.546488947 -0500
@@ -23,7 +23,11 @@
 #include "propertiesdlg.h"
 #include "icondlg.h"
 #include "mainwindow.h"
+#ifdef __FreeBSD__
+#include <sys/mount.h>
+#else
 #include <sys/vfs.h>
+#endif
 #include <sys/stat.h>
 #include <magic.h>
 
