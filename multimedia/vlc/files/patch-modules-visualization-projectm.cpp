--- modules/visualization/projectm.cpp.orig
+++ modules/visualization/projectm.cpp
@@ -25,6 +25,9 @@
 #ifdef HAVE_CONFIG_H
 # include "config.h"
 #endif
+#ifdef HAVE_XLOCALE_H
+# include <xlocale.h>
+#endif
 #ifndef __STDC_CONSTANT_MACROS
 # define __STDC_CONSTANT_MACROS
 #endif
