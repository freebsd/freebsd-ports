--- src/SysTray.cpp.orig	Tue Feb 17 16:43:12 2004
+++ src/SysTray.cpp	Tue Feb 17 16:43:53 2004
@@ -22,8 +22,8 @@
 #include "sys.h"
 #include <libintl.h>
 #include <clocale>		// Needed for setlocale(3)
-#include <net/if.h>		// Needed for struct ifreq
 #include <sys/socket.h>		//
+#include <net/if.h>		// Needed for struct ifreq
 #include <netinet/in.h>		// Needed for inet_ntoa
 #include <arpa/inet.h>		//
 #include <sys/ioctl.h>		// Needed for SIOCGIFADDR
