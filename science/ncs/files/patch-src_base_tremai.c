--- src/base/tremai.c.orig	2011-04-11 18:26:06.000000000 +0200
+++ src/base/tremai.c	2014-03-26 23:51:58.000000000 +0100
@@ -45,6 +45,7 @@
 #include <string.h>
 
 #if defined(HAVE_SYS_RESOURCE_H)
+#include <sys/types.h>
 #include <sys/resource.h>
 #endif
 
