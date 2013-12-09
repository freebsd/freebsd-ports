--- ./plugins/stardict/mapfile.hpp.orig	2011-12-05 12:40:49.000000000 +0000
+++ ./plugins/stardict/mapfile.hpp	2013-12-07 17:36:45.942541049 +0000
@@ -9,6 +9,7 @@
 #  include <sys/types.h>
 #  include <fcntl.h>
 #  include <sys/mman.h>
+#  include <unistd.h>
 #endif
 #ifdef _WIN32
 #  include <windows.h>
