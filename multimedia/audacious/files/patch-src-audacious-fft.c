--- src/audacious/fft.c.orig	2014-06-25 12:30:54.752468573 +0200
+++ src/audacious/fft.c	2014-06-25 12:32:43.785461802 +0200
@@ -30,6 +30,13 @@
 static float complex roots[N / 2];    /* N-th roots of unity */
 static char generated = 0;            /* set if tables have been generated */
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version < 900000
+#define cexpf(x) (expf(crealf(x))*(cosf(cimagf(x))+sinf(cimagf(x))*I))
+#endif
+#endif
+
 /* Reverse the order of the lowest LOGN bits in an integer. */
 
 static int bit_reverse (int x)
