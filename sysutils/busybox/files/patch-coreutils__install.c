--- ./coreutils/install.c.orig	2011-08-22 04:57:49.000000000 +0200
+++ ./coreutils/install.c	2011-09-22 23:05:09.000000000 +0200
@@ -26,6 +26,8 @@
 #include "libbb.h"
 #include "libcoreutils/coreutils.h"
 
+#include <libgen.h>
+
 #if ENABLE_FEATURE_INSTALL_LONG_OPTIONS
 static const char install_longopts[] ALIGN1 =
 	"directory\0"           No_argument       "d"
