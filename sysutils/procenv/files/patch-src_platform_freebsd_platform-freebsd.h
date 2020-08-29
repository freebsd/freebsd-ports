--- src/platform/freebsd/platform-freebsd.h.orig	2019-08-02 20:40:49 UTC
+++ src/platform/freebsd/platform-freebsd.h
@@ -22,8 +22,8 @@
 #include "platform.h"
 #include "util.h"
 
-#if defined (HAVE_SYS_CAPABILITY_H)
-#include <sys/capability.h>
+#if defined (HAVE_SYS_CAPSICUM_H)
+#include <sys/capsicum.h>
 
 #if __FreeBSD__ == 9
 
