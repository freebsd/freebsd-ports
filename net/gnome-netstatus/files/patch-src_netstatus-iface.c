--- src/netstatus-iface.c.orig	Mon Mar 22 17:49:17 2004
+++ src/netstatus-iface.c	Mon Mar 22 17:50:12 2004
@@ -32,6 +32,8 @@
 
 #include <libgnome/gnome-i18n.h>
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/ioctl.h>
 #ifdef HAVE_SYS_SOCKIO_H
 #include <sys/sockio.h>
@@ -39,6 +41,7 @@
 #include <sys/param.h>
 #include <net/if.h>
 #include <net/if_arp.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <errno.h>
 #include <unistd.h>
