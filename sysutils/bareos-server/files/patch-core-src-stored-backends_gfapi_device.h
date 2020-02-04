--- core/src/stored/backends/gfapi_device.h	2020-02-03 01:55:43.902693000 -0500
+++ core/src/stored/backends/gfapi_device.h	2020-02-03 01:52:28.885974000 -0500
@@ -28,7 +28,7 @@
 #ifndef BAREOS_STORED_BACKENDS_GFAPI_DEVICE_H_
 #define BAREOS_STORED_BACKENDS_GFAPI_DEVICE_H_
 
-#include <api/glfs.h>
+#include <glusterfs/api/glfs.h>
 
 #if defined GLFS_FTRUNCATE_HAS_FOUR_ARGS
 #define glfs_ftruncate(fd, offset) glfs_ftruncate(fd, offset, NULL, NULL)
