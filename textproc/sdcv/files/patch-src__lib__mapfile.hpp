--- src/lib/mapfile.hpp.orig	2013-07-06 22:28:17 UTC
+++ src/lib/mapfile.hpp
@@ -4,6 +4,9 @@
 #  include "config.h"
 #endif
 
+#include <cstdlib>
+#include <unistd.h>
+
 #ifdef HAVE_MMAP
 #  include <sys/types.h>
 #  include <fcntl.h>
