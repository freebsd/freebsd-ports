--- lib/if_pfkeyv2.h.orig	2018-08-15 21:36:53.000000000 -0700
+++ lib/if_pfkeyv2.h	2018-10-19 12:48:45.115311000 -0700
@@ -29,6 +29,7 @@
  * SUCH DAMAGE.
  */
 
+#include "config.h"
 #include <sys/socket.h>
 #ifdef HAVE_NET_PFKEYV2_H
 # include <net/pfkeyv2.h>
