--- crypto/engine/hw_cryptodev.c.orig	Thu Jan 23 09:10:07 2003
+++ crypto/engine/hw_cryptodev.c	Mon Aug  4 05:39:28 2003
@@ -35,7 +35,7 @@
 
 #if (defined(__unix__) || defined(unix)) && !defined(USG)
 #include <sys/param.h>
-# if (OpenBSD >= 200112) || ((__FreeBSD_version >= 470101 && __FreeBSD_version < 500000) || __FreeBSD_version >= 500041)
+# if (OpenBSD >= 200112) || ((__FreeBSD_version > 470101 && __FreeBSD_version < 500000) || __FreeBSD_version >= 500041)
 # define HAVE_CRYPTODEV
 # endif
 # if (OpenBSD >= 200110)
