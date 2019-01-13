--- src/platform/freebsd/platform-freebsd.h.orig	2017-10-16 17:35:19 UTC
+++ src/platform/freebsd/platform-freebsd.h
@@ -23,7 +23,8 @@
 #include "util.h"
 
 #if defined (HAVE_SYS_CAPABILITY_H)
-#include <sys/capability.h>
+/* #include <sys/capability.h> */
+#include <sys/capsicum.h>
 
 #if __FreeBSD__ == 9
 
