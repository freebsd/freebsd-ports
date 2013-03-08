--- include/clplumbing/cl_uuid.h.orig	2013-02-07 16:26:11.000000000 +0000
+++ include/clplumbing/cl_uuid.h	2013-02-07 16:26:18.000000000 +0000
@@ -16,7 +16,7 @@
 
 #ifndef _CL_UUID_H_
 #define _CL_UUID_H_
-#include <glib/gtypes.h>
+#include <glib.h>
 
 typedef struct cl_uuid_s{	
 	unsigned char	uuid[16];
