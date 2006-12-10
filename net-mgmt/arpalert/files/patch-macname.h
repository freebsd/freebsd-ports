--- macname.h.orig	Sun Dec 10 22:52:45 2006
+++ macname.h	Sun Dec 10 22:53:04 2006
@@ -7,6 +7,7 @@
 #ifndef __MACNAME_H__
 #define __MACNAME_H__
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <net/if.h>
 #include <net/if_arp.h>
