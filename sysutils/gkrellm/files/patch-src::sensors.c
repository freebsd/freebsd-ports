Index: src/sensors.c
diff -u src/sensors.c.orig src/sensors.c
--- src/sensors.c.orig	Mon Oct 28 05:23:27 2002
+++ src/sensors.c	Mon Oct 28 05:23:41 2002
@@ -223,7 +223,9 @@
 #if defined(__FreeBSD__) && defined(__i386__)
 #include <osreldate.h>
 #include <machine/cpufunc.h>
-#if __FreeBSD_version >= 300000
+#if __FreeBSD_version >= 500042
+#include <dev/smbus/smb.h>
+#elif __FreeBSD_version >= 300000
 #include <machine/smb.h>
 #endif
 
