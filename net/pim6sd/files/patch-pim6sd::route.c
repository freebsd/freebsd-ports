--- pim6sd/route.c	Tue Nov 19 03:17:26 2002
+++ pim6sd/route.c	Tue Nov 19 03:17:09 2002
@@ -48,6 +48,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/param.h>
 #include <net/if.h>
 #include <net/route.h>
 #include <netinet/in.h>
