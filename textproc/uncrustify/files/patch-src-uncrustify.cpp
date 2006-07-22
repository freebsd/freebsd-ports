--- src/uncrustify.cpp.orig	Wed Jul 19 20:39:15 2006
+++ src/uncrustify.cpp	Wed Jul 19 20:39:48 2006
@@ -15,6 +15,7 @@
 #include "logger.h"
 #include "log_levels.h"
 
+#include <libgen.h>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
