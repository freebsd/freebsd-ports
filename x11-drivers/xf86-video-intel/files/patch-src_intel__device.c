--- src/intel_device.c.orig	2014-12-21 20:36:40.268102983 +0100
+++ src/intel_device.c	2014-12-21 20:36:01.358104504 +0100
@@ -28,6 +28,9 @@
 #include "config.h"
 #endif
 
+#define _WITH_GETLINE	/* to expose getline() in stdio.h on FreeBSD */
+#include <stdio.h>	/* for getline() */
+
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <assert.h>
