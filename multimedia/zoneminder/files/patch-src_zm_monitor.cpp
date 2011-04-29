--- src/zm_monitor.cpp.orig	2009-06-24 14:22:23.000000000 +0400
+++ src/zm_monitor.cpp	2011-04-08 17:48:07.389805307 +0400
@@ -43,6 +43,7 @@
 #include <sys/mman.h>
 #include <fcntl.h>
 #else // ZM_MEM_MAPPED
+#include <unistd.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>
 #endif // ZM_MEM_MAPPED
