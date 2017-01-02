--- macname.h.orig	2011-11-08 19:36:51 UTC
+++ macname.h
@@ -7,6 +7,7 @@
 #ifndef __MACNAME_H__
 #define __MACNAME_H__
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <net/if.h>
 #include <net/if_arp.h>
