--- pim6sd/cfparse.y.orig	Tue Nov 19 03:27:18 2002
+++ pim6sd/cfparse.y	Tue Nov 19 03:27:33 2002
@@ -31,6 +31,7 @@
 %{
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/param.h>
 #include <net/if.h>
 #include <net/route.h>
 #include <netinet/in.h>
