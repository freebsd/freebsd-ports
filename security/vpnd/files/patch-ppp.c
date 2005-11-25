--- ppp.c.orig	Wed Sep 14 16:43:48 2005
+++ ppp.c	Thu Sep 15 16:41:52 2005
@@ -45,6 +45,7 @@
 
 #define USE_PPP		/* workaround for OpenBSD 3.0 dup struct vjstat */
 #include "vpnd.h"
+#include <net/if_ppp.h>
 
 #if defined(SunOS)
 #define _PPPIO(n)     (('p' << 8) + (n))
