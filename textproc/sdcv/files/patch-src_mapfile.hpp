--- src/mapfile.hpp.orig	2017-04-22 18:44:35 UTC
+++ src/mapfile.hpp
@@ -4,6 +4,9 @@
 #  include "config.h"
 #endif
 
+#include <cstdlib>
+#include <unistd.h>
+
 #ifdef HAVE_MMAP
 #  include <sys/types.h>
 #  include <fcntl.h>
