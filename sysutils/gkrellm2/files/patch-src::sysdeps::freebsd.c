Index: src/sysdeps/freebsd.c
diff -u src/sysdeps/freebsd.c.orig src/sysdeps/freebsd.c
--- src/sysdeps/freebsd.c.orig	Wed Oct  2 05:17:59 2002
+++ src/sysdeps/freebsd.c	Mon Oct 28 05:13:38 2002
@@ -1210,7 +1210,9 @@
 #include <dirent.h>
 #include <osreldate.h>
 #include <machine/cpufunc.h>
-#if __FreeBSD_version >= 300000
+#if __FreeBSD_version >= 500042
+#include <dev/smbus/smb.h>
+#elif __FreeBSD_version >= 300000
 #include <machine/smb.h>
 #endif
 
