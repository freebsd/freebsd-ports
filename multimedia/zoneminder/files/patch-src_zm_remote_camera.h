--- src/zm_remote_camera.h.orig	2009-05-28 12:47:59.000000000 +0400
+++ src/zm_remote_camera.h	2011-04-08 17:48:07.392807144 +0400
@@ -21,7 +21,7 @@
 #define ZM_REMOTE_CAMERA_H
 
 #include "zm_camera.h"
-
+#include <netinet/in.h>
 #include <string>
 #include <netdb.h>
 
