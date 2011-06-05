--- src/zm_monitor.cpp.orig	2011-03-02 15:23:10.000000000 +0300
+++ src/zm_monitor.cpp	2011-05-05 18:31:35.028176099 +0400
@@ -45,6 +45,7 @@
 #include <sys/mman.h>
 #include <fcntl.h>
 #else // ZM_MEM_MAPPED
+#include <unistd.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>
 #endif // ZM_MEM_MAPPED
