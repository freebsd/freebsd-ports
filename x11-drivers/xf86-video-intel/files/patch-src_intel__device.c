--- src/intel_device.c.orig	2017-02-28 20:52:19 UTC
+++ src/intel_device.c
@@ -28,6 +28,9 @@
 #include "config.h"
 #endif
 
+#define _WITH_GETLINE	/* to expose getline() in stdio.h on FreeBSD */
+#include <stdio.h>	/* for getline() */
+
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <assert.h>
@@ -204,6 +207,7 @@ static inline struct intel_device *intel
 }
 
 static const char *kernel_module_names[] ={
+	"i915kms",
 	"i915",
 	NULL,
 };
