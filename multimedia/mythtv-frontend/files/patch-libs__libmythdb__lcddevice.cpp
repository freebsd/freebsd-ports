--- libs/libmythdb/lcddevice.cpp.orig	2009-08-15 12:38:39.000000000 +0200
+++ libs/libmythdb/lcddevice.cpp	2009-12-18 12:22:32.000000000 +0100
@@ -19,6 +19,7 @@
 #   include <sys/sysinfo.h>
 # else
 #   ifdef __FreeBSD__
+#     include <sys/param.h>
 #     include <sys/mount.h>
 #   endif
 #   if CONFIG_CYGWIN

