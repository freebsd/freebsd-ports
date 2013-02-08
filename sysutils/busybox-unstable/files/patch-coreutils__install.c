--- ./coreutils/install.c.orig	2012-06-26 13:35:45.000000000 +0000
+++ ./coreutils/install.c	2012-07-17 02:08:37.000000000 +0000
@@ -26,6 +26,8 @@
 #include "libbb.h"
 #include "libcoreutils/coreutils.h"
 
+#include <libgen.h>
+
 #if ENABLE_FEATURE_INSTALL_LONG_OPTIONS
 static const char install_longopts[] ALIGN1 =
 	"directory\0"           No_argument       "d"
