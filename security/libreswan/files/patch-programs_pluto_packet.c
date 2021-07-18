--- programs/pluto/packet.c.orig	2021-05-21 23:54:59 UTC
+++ programs/pluto/packet.c
@@ -22,6 +22,7 @@
 #include <stddef.h>
 #include <netinet/in.h>
 #include <string.h>
+#include <sys/socket.h>
 
 #include "constants.h"
 #include "lswalloc.h"
