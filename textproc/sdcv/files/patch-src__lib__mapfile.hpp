--- src/lib/mapfile.hpp.orig
+++ src/lib/mapfile.hpp
@@ -5,6 +5,9 @@
 #  include "config.h"
 #endif
 
+#include <cstdlib>
+#include <unistd.h>
+
 #ifdef HAVE_MMAP
 #  include <sys/types.h>
 #  include <fcntl.h>
