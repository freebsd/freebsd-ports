--- src/xxxprotocol.cpp.orig	2008-06-29 19:17:33.000000000 +0100
+++ src/xxxprotocol.cpp		2008-07-02 13:20:41.000000000 +0100
@@ -8,6 +8,7 @@
 #include <quuid.h>
 #include <qsocketnotifier.h>
 #include <qmessagebox.h>
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
@@ -17,12 +18,11 @@
 #include <unistd.h>
 #include <fcntl.h>
 
-#ifdef FREEBSD
+#ifdef BSD
 #include <err.h>
 #include <errno.h>
 #include <net/if.h>
 #include <sys/sysctl.h>
-#include <sys/param.h>
 #include <netinet/if_ether.h>
 #include <net/route.h>
 #include <net/if_dl.h>
@@ -207,7 +207,7 @@
 QString XXXProtocol::getHWAddr(const QString& addr, const QString& iface)
 { 
     QString macaddr(tr("Unknown"));
-#ifdef BSD
+#if defined ( BSD )
     struct sockaddr_inarp addr_inarp;
 
     bzero(&addr_inarp, sizeof(addr_inarp));
@@ -249,7 +249,7 @@
     return macaddr;
 }
 
-#ifdef BSD
+#if defined ( BSD )
 struct sockaddr_dl * XXXProtocol::search(u_long addr)
 {
     int mib[6];
