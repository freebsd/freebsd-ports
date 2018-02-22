--- retroshare-gui/src/gui/elastic/fft.h.orig	2017-04-21 15:57:46 UTC
+++ retroshare-gui/src/gui/elastic/fft.h
@@ -85,6 +85,7 @@

 #pragma once
 #include <math.h>
+#include <sys/param.h>

 class fft
 {
@@ -106,6 +107,9 @@
 			for (j = 2; j <= nwh - 2; j += 2) {
 #ifdef __APPLE__
 				__sincos(delta*j,&y,&x);
+#elif defined __clang__ && defined __FreeBSD_version && __FreeBSD_version < 1200000
+				x = cos(delta * j);
+				y = sin(delta * j);
 #else
 				sincos(delta*j,&y,&x) ;
 #endif

