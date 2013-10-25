--- src/logging/Manager.cc.orig	2013-10-24 11:44:30.000000000 -0700
+++ src/logging/Manager.cc	2013-10-24 11:45:09.000000000 -0700
@@ -1,6 +1,7 @@
 // See the file "COPYING" in the main distribution directory for copyright.
 
 #include <algorithm>
+#include <unistd.h>				/* pick up usleep() prototype */
 
 #include "../Event.h"
 #include "../EventHandler.h"
