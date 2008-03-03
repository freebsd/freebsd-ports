--- br.cpp.orig	Thu Feb 28 15:12:00 2008
+++ br.cpp	Thu Feb 28 15:12:12 2008
@@ -28,6 +28,7 @@
 #include <sys/mman.h>
 #include <fcntl.h>
 #include <syslog.h>
+#include <strfunc.h>
 #include "br.h"
 
 buffered_reader::buffered_reader(int cur_fd, int cur_block_size)
