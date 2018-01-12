--- br.cpp.orig	2017-12-27 12:07:16 UTC
+++ br.cpp
@@ -12,6 +12,7 @@
 #include <sys/mman.h>
 #include <fcntl.h>
 #include <syslog.h>
+#include <strfunc.h>
 #include "br.h"
 
 buffered_reader::buffered_reader(int cur_fd, int cur_block_size)
