--- libannex/ip_layer.c.orig	Thu Aug  4 15:57:47 1994
+++ libannex/ip_layer.c	Thu Sep 18 20:18:15 2003
@@ -63,6 +63,8 @@
  *****************************************************************************/
 
 #include <sys/types.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <stdio.h>
 #include "../inc/config.h"
 #include "port/port.h"
