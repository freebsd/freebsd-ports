--- src/netstatus-iface.c.orig	Tue Nov 30 18:35:23 2004
+++ src/netstatus-iface.c	Tue Nov 30 18:35:43 2004
@@ -33,6 +33,7 @@
 
 #include <libgnome/gnome-i18n.h>
 
+#include <sys/types.h>
 #include <sys/ioctl.h>
 #ifdef HAVE_SYS_SOCKIO_H
 #include <sys/sockio.h>
@@ -41,6 +42,7 @@
 #include <sys/socket.h>
 #include <net/if.h>
 #include <net/if_arp.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <errno.h>
 #include <unistd.h>
