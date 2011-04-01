--- ppapi/proxy/image_data.cc.orig	2011-03-15 05:44:04.000000000 +0200
+++ ppapi/proxy/image_data.cc	2011-03-15 05:48:26.000000000 +0200
@@ -4,7 +4,7 @@
 
 #include "ppapi/proxy/image_data.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined (OS_FREEBSD)
 #include <sys/shm.h>
 #endif
 
