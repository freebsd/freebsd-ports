--- ./src/lib/random.cpp.orig	2009-06-28 14:22:31.000000000 +0000
+++ ./src/lib/random.cpp	2013-09-21 15:37:54.599146989 +0000
@@ -19,6 +19,7 @@
  ***************************************************************************/
 
 #include "random.h"
+#include <unistd.h>
 
 
 #if defined(Q_WS_X11) || defined(Q_WS_MAC)
