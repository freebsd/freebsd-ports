--- plugins/stardict/mapfile.hpp.orig	2011-12-05 12:40:49 UTC
+++ plugins/stardict/mapfile.hpp
@@ -9,6 +9,7 @@
 #  include <sys/types.h>
 #  include <fcntl.h>
 #  include <sys/mman.h>
+#  include <unistd.h>
 #endif
 #ifdef _WIN32
 #  include <windows.h>
