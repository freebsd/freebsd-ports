--- src/SysTray.cpp.orig	Tue Jul  6 07:32:56 2004
+++ src/SysTray.cpp	Tue Jul  6 07:33:44 2004
@@ -23,8 +23,8 @@
 #include "sys.h"
 #include <libintl.h>
 #include <clocale>		// Needed for setlocale(3)
-#include <net/if.h>		// Needed for struct ifreq
 #include <sys/socket.h>		//
+#include <net/if.h>		// Needed for struct ifreq
 #include <netinet/in.h>		// Needed for inet_ntoa
 #include <arpa/inet.h>		//
 #include <sys/ioctl.h>		// Needed for SIOCGIFADDR
