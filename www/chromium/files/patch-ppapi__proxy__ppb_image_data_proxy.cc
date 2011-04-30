--- ppapi/proxy/ppb_image_data_proxy.cc.orig	2011-04-19 21:36:29.491038804 +0300
+++ ppapi/proxy/ppb_image_data_proxy.cc	2011-04-19 21:37:11.973039170 +0300
@@ -21,7 +21,7 @@
 #include "ppapi/proxy/ppapi_messages.h"
 #include "ppapi/shared_impl/image_data_impl.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined (OS_FREEBSD)
 #include <sys/shm.h>
 #elif defined(OS_MACOSX)
 #include <sys/stat.h>
