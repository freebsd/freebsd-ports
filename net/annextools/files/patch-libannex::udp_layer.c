--- libannex/udp_layer.c.orig	Thu Aug  4 15:59:14 1994
+++ libannex/udp_layer.c	Thu Sep 18 20:10:32 2003
@@ -63,7 +63,9 @@
  *****************************************************************************/
 
 #include <stdio.h>
+#include <errno.h>
 #include <sys/types.h>
+#include <netinet/in.h>
 #include "../inc/config.h"
 #include "port/port.h"
 #include "../inc/slip/slip_user.h"
