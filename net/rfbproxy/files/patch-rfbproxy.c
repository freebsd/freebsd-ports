--- rfbproxy.c.orig	Wed Oct  9 14:23:44 2002
+++ rfbproxy.c	Wed Oct  9 14:25:19 2002
@@ -60,8 +60,10 @@
 # include <stdint.h>
 #else
 # if HAVE_U_INTXX_T
+#  ifndef __FreeBSD__
 typedef u_int16_t uint16_t;
 typedef u_int32_t uint32_t;
+#  endif
 # else
 typedef unsigned short uint16_t;
 typedef unsigned long uint32_t;
