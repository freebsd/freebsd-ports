--- libng/plugins/read-qt.c.orig	Fri Feb 14 15:13:43 2003
+++ libng/plugins/read-qt.c	Tue Nov  8 09:09:45 2005
@@ -4,9 +4,9 @@
 #include <stdio.h>
 #include <string.h>
 #include <pthread.h>
-#include <quicktime/quicktime.h>
-#include <quicktime/colormodels.h>
-#include <quicktime/lqt.h>
+#include <lqt/quicktime.h>
+#include <lqt/colormodels.h>
+#include <lqt/lqt.h>
 
 #include "grab-ng.h"
 
