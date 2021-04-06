--- crypto/engine/eng_cryptodev.c.orig	2017-07-06 01:00:00 UTC
+++ crypto/engine/eng_cryptodev.c
@@ -35,7 +35,7 @@
 #if (defined(__unix__) || defined(unix)) && !defined(USG) && \
         (defined(OpenBSD) || defined(__FreeBSD__))
 # include <sys/param.h>
-# if (OpenBSD >= 200112) || ((__FreeBSD_version >= 470101 && __FreeBSD_version < 500000) || __FreeBSD_version >= 500041)
+# if (OpenBSD >= 200112) || ((__FreeBSD_version >= 470101 && __FreeBSD_version < 500000) || (__FreeBSD_version >= 500041 && __FreeBSD_version < 1300000))
 #  define HAVE_CRYPTODEV
 # endif
 # if (OpenBSD >= 200110)
