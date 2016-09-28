--- src/freebsd.h.orig	2016-07-20 16:53:48 UTC
+++ src/freebsd.h
@@ -7,6 +7,7 @@
 #include <sys/param.h>
 #include <sys/mount.h>
 #include <sys/ucred.h>
+#include <strings.h>
 #include <fcntl.h>
 #include <kvm.h>
 #if (defined(i386) || defined(__i386__))
