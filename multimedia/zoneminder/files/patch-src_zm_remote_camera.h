--- src/zm_remote_camera.h.orig	2009-06-02 00:59:26.000000000 -0700
+++ src/zm_remote_camera.h	2014-07-23 00:39:49.000000000 -0700
@@ -21,9 +21,10 @@
 #define ZM_REMOTE_CAMERA_H
 
 #include "zm_camera.h"
-
+#include <netinet/in.h>
 #include <string>
 #include <netdb.h>
+#include <unistd.h>
 
 //
 // Class representing 'remote' cameras, i.e. those which are
