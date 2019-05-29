--- src/framework/engine.h.orig	2018-12-20 14:37:12 UTC
+++ src/framework/engine.h
@@ -10,6 +10,9 @@
 #include <map>
 #include <vector>
 #include <string>
+#ifdef __FreeBSD__
+#include <sys/select.h>
+#endif
 
 #include "logger.h"
 
