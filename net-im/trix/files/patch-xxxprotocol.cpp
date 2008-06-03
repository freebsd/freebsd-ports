--- src/xxxprotocol.cpp.orig	2008-01-04 18:25:54.000000000 +0200
+++ src/xxxprotocol.cpp		2008-04-21 01:19:07.000000000 +0300
@@ -8,6 +8,7 @@
 #include <quuid.h>
 #include <qsocketnotifier.h>
 #include <qmessagebox.h>
+#include <sys/param.h>
 #ifdef WIN32
 #include <winsock.h>
 #else
@@ -21,7 +22,7 @@
 #include <fcntl.h>
 #endif
 
-#ifdef FREEBSD
+#ifdef BSD
 #include <err.h>
 #include <errno.h>
 #include <net/if.h>
@@ -223,7 +224,7 @@
 QString XXXProtocol::getHWAddr(const QString& addr, const QString& iface)
 { 
     QString macaddr(tr("Unknown"));
-#if defined( FREEBSD )
+#if defined( BSD )
     struct sockaddr_inarp addr_inarp;
 
     bzero(&addr_inarp, sizeof(addr_inarp));
@@ -265,7 +266,7 @@
     return macaddr;
 }
 
-#if defined( FREEBSD )
+#if defined( BSD )
 struct sockaddr_dl * XXXProtocol::search(u_long addr)
 {
     int mib[6];
