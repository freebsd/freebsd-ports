--- avahi-ui/avahi-ui.c.orig	Fri Apr 20 20:07:43 2007
+++ avahi-ui/avahi-ui.c	Fri Apr 20 20:09:03 2007
@@ -23,6 +23,8 @@
 #include <config.h>
 #endif
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <string.h>
 #include <stdarg.h>
 #include <net/if.h>
