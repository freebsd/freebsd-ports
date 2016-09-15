--- libnal/proto_fd.c.orig	2003-11-27 00:02:32 UTC
+++ libnal/proto_fd.c
@@ -24,6 +24,7 @@
 #include <libnal/nal.h>
 #include "nal_internal.h"
 #include <libsys/post.h>
+#include <sys/limits.h>
 
 /**************************/
 /* predeclare our vtables */
