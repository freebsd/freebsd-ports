--- knetworkconf/knetworkconf/knetworkconfigparser.cpp.orig	2009-07-28 21:43:49.000000000 +0200
+++ knetworkconf/knetworkconf/knetworkconfigparser.cpp	2010-06-15 07:23:42.039626265 +0200
@@ -21,6 +21,10 @@
 #include <QPixmap>
 #include <QTextStream>
 #include <Q3PtrList>
+#ifdef Q_OS_FREEBSD
+#include <net/if_dl.h>
+#include <net/route.h>
+#endif
 
 KNetworkConfigParser::KNetworkConfigParser(){
   networkInfo = new KNetworkInfo();
@@ -184,7 +188,8 @@
 }
 
 /**
-  Reads /proc/net/route looking for the default gateway.
+  Reads /proc/net/route or asks to a routing socket (FreeBSD)
+  looking for the default gateway.
 
   NOTE:We should use the gateway reported by gst, but if there's a
   gw in a config file and one of the network interfaces is
@@ -193,22 +198,87 @@
 */
 void KNetworkConfigParser::loadRoutingInfo( KRoutingInfo *routingInfo){
 //  routingInfo = NULL;
-  QFile f( "/proc/net/route");
+#ifdef Q_OS_FREEBSD
+  int sfd = socket(PF_ROUTE, SOCK_RAW, AF_UNSPEC);
+  if (sfd < 0) {
+    KMessageBox::error(0,
+                        i18n("Could not open the routing socket."),
+                        i18n("Could Not Open Socket"));
+    return;
+  }
+  int pid = getpid();
+  const int buflen = sizeof(struct rt_msghdr) + 512;
+  int seq = 1138;
+  char *buf = (char *)calloc(1, buflen);
+  struct rt_msghdr *rtm = (struct rt_msghdr *)buf;
+  struct sockaddr *sin = (struct sockaddr *)(rtm + 1);
+  sin->sa_len = sizeof(struct sockaddr_in6);
+  sin->sa_family = AF_INET6;
+  struct sockaddr_dl *ifp = (struct sockaddr_dl *)((struct sockaddr_in6 *)sin + 1);
+  ifp->sdl_len = sizeof(struct sockaddr_dl);
+  ifp->sdl_family = AF_LINK;
+  rtm->rtm_msglen = sizeof(struct rt_msghdr) + sin->sa_len + ifp->sdl_len;
+  rtm->rtm_version = RTM_VERSION;
+  rtm->rtm_type = RTM_GET;
+  rtm->rtm_flags = RTF_UP | RTF_GATEWAY | RTF_HOST | RTF_STATIC;
+  rtm->rtm_addrs = RTA_DST | RTA_NETMASK | RTA_IFP;
+  rtm->rtm_pid = pid;
+  rtm->rtm_seq = seq;
+  if (write(sfd, buf, rtm->rtm_msglen) < 0) {
+    sin->sa_len = sizeof(struct sockaddr_in);
+    sin->sa_family = AF_INET;
+    ifp = (struct sockaddr_dl *)memmove((struct sockaddr_in *)sin + 1, ifp, ifp->sdl_len);
+    rtm->rtm_msglen = sizeof(struct rt_msghdr) + sin->sa_len + ifp->sdl_len;
+    rtm->rtm_seq = ++seq;
+    if (write(sfd, buf, rtm->rtm_msglen) < 0) {
+      KMessageBox::error(0,
+                          i18n("Could not write to the routing socket: the connection may be down, or you don't have such a permission."),
+                          i18n("Could Not Write to Socket"));
+      return;
+    }
+  }
+  int n;
+  do {
+    n = read(sfd, buf, buflen);
+  } while (n > 0 && (rtm->rtm_seq != seq || rtm->rtm_pid != pid));
+  if (n < 0) {
+    KMessageBox::error(0,
+                        i18n("Could not get information about the gateway."),
+                        i18n("Could Not Read From Socket"));
+    return;
+  }
+  buf = (char *)(rtm + 1);
+  if (rtm->rtm_addrs & RTA_GATEWAY || rtm->rtm_addrs & RTA_IFP)
+    for (int i = 1; i; i <<= 1) {
+      if (i & rtm->rtm_addrs) {
+        struct sockaddr *sa = (struct sockaddr *)buf;
+        if (i == RTA_GATEWAY) {
+          if (sa->sa_family == AF_INET6)
+            routingInfo->setGateway(inet_ntop(AF_INET6, &(((struct sockaddr_in6 *)sa)->sin6_addr), (buf - INET6_ADDRSTRLEN), INET6_ADDRSTRLEN));
+          else if (sa->sa_family == AF_INET)
+            routingInfo->setGateway(inet_ntop(AF_INET, &(((struct sockaddr_in *)sa)->sin_addr), (buf - INET_ADDRSTRLEN), INET_ADDRSTRLEN));
+        } else if (i == RTA_IFP && sa->sa_family == AF_LINK && ((struct sockaddr_dl *)sa)->sdl_nlen)
+          routingInfo->setGatewayDevice(((struct sockaddr_dl *)sa)->sdl_data);
+        buf += SA_SIZE(sa);
+      }
+    }
+#else
+  QString fname = "/proc/net/route";
+  QFile f(fname);
   if ( !f.open(QIODevice::ReadOnly) )
   {
 //    return routingInfo;
     KMessageBox::error(0,
-                        i18n("Could not open file /proc/net/route."),
+                        i18n("Could not open file %1.", fname),
                         i18n("Could Not Open File"));
   }
   else
   {
 //    routingInfo = new KRoutingInfo();
     QTextStream t( &f );        // use a text stream
-    QString s;
     while (!t.atEnd())
     {
-      s = t.readLine();       // line of text excluding '\n'
+      QString s = t.readLine();       // line of text excluding '\n'
       QString interface = s.section('\t',0,0);
       QString destination = s.section('\t',1,1);
       QString gw = s.section('\t',2,2);
@@ -222,6 +292,7 @@
     }
   }
   f.close();
+#endif
 }
 QString
 KNetworkConfigParser::hexIPv4ToDecIPv4(const QString &hex)
