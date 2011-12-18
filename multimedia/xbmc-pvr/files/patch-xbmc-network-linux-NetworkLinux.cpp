--- xbmc/network/linux/NetworkLinux.cpp.orig
+++ xbmc/network/linux/NetworkLinux.cpp
@@ -23,14 +23,14 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <linux/if.h>
 #include <linux/wireless.h>
 #include <linux/sockios.h>
 #endif
 #include <errno.h>
 #include <resolv.h>
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/sockio.h>
 #include <net/if.h>
 #include <net/if_dl.h>
@@ -42,6 +42,9 @@
 #include "NetworkLinux.h"
 #include "Util.h"
 #include "utils/log.h"
+#if defined(__FreeBSD__)
+#include <net/route.h>
+#endif
 
 using namespace std;
 
@@ -64,7 +67,7 @@ CStdString& CNetworkInterfaceLinux::GetN
 
 bool CNetworkInterfaceLinux::IsWireless()
 {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   return false;
 #else
   struct iwreq wrq;
@@ -144,7 +147,7 @@ CStdString CNetworkInterfaceLinux::GetCu
 {
    CStdString result = "";
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    char essid[IW_ESSID_MAX_SIZE + 1];
    memset(&essid, 0, sizeof(essid));
 
@@ -166,7 +169,84 @@ CStdString CNetworkInterfaceLinux::GetCu
 {
    CStdString result = "";
 
-#ifndef __APPLE__
+#if defined(__FreeBSD__)
+  struct {
+  	struct  rt_msghdr m_rtm;
+  	char    m_space[512];
+  } m_rtmsg;
+  int s, seq, l, pid, rtm_addrs, i;
+  struct sockaddr so_dst, so_mask;
+  struct  rt_msghdr rtm;
+  char *cp = m_rtmsg.m_space;
+  struct sockaddr *gate = NULL, *sa;
+  struct  rt_msghdr *rtm_aux;
+
+#define ROUNDUP(a) \
+	        ((a) > 0 ? (1 + (((a) - 1) | (sizeof(long) - 1))) : sizeof(long))
+
+#define NEXTADDR(w, u) \
+        if (rtm_addrs & (w)) {\
+            l = ROUNDUP(u.sa_len); memmove(cp, &(u), l); cp += l;\
+        }
+
+#define ADVANCE(x, n) (x += ROUNDUP((n)->sa_len))
+
+  pid = getpid();
+  seq = 0;
+  rtm_addrs = RTA_DST | RTA_NETMASK;
+
+  bzero(&so_dst, sizeof(so_dst));
+  bzero(&so_mask, sizeof(so_mask));
+  bzero(&rtm, sizeof(struct rt_msghdr));
+
+  rtm.rtm_type = RTM_GET;
+  rtm.rtm_flags = RTF_UP | RTF_GATEWAY;
+  rtm.rtm_version = RTM_VERSION;
+  rtm.rtm_seq = ++seq;
+  rtm.rtm_addrs = rtm_addrs; 
+
+  so_dst.sa_family = AF_INET;
+  so_dst.sa_len = sizeof(struct sockaddr_in);
+  so_mask.sa_family = AF_INET;
+  so_mask.sa_len = sizeof(struct sockaddr_in);
+
+  NEXTADDR(RTA_DST, so_dst);
+  NEXTADDR(RTA_NETMASK, so_mask);
+
+  rtm.rtm_msglen = l = cp - (char *)&m_rtmsg;
+
+  s = socket(PF_ROUTE, SOCK_RAW, 0);
+
+  if (write(s, (char *)&m_rtmsg, l) < 0)
+    return result;
+
+  do {
+    l = read(s, (char *)&m_rtmsg, sizeof(m_rtmsg));
+  } while (l > 0 && (rtm.rtm_seq != seq || rtm.rtm_pid != pid));
+                        
+  close(s);
+
+  rtm_aux = &rtm;
+
+  cp = ((char *)(rtm_aux + 1));
+  if (rtm_aux->rtm_addrs) {
+    for (i = 1; i; i <<= 1)
+      if (i & rtm_aux->rtm_addrs) {
+	    sa = (struct sockaddr *)cp;
+	    if (i == RTA_GATEWAY)
+	      gate = sa;
+	    ADVANCE(cp, sa);
+      }
+  }
+  else
+      return result;
+
+  if (gate != NULL)
+	result = inet_ntoa(((struct sockaddr_in *)gate)->sin_addr);
+
+  return result;
+
+#elif !defined(__APPLE__)
    FILE* fp = fopen("/proc/net/route", "r");
    if (!fp)
    {
@@ -267,7 +347,7 @@ CNetworkInterface* CNetworkLinux::GetFir
 CStdString CNetworkLinux::GetMacAddress(CStdString interfaceName)
 {
   CStdString result = "00:00:00:00:00:00";
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 
 #if ! defined(IFT_ETHER)
 #define IFT_ETHER 0x6/* Ethernet CSMACD */
@@ -333,7 +413,7 @@ void CNetworkLinux::queryInterfaceList()
   CStdString macAddr = "";
   m_interfaces.clear();
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 
    // Query the list of interfaces.
    struct ifaddrs *list;
@@ -352,7 +432,6 @@ void CNetworkLinux::queryInterfaceList()
    }
 
    freeifaddrs(list);
-
 #else
    FILE* fp = fopen("/proc/net/dev", "r");
    if (!fp)
@@ -394,7 +473,7 @@ void CNetworkLinux::queryInterfaceList()
 std::vector<CStdString> CNetworkLinux::GetNameServers(void)
 {
    std::vector<CStdString> result;
-#ifndef __APPLE__
+#if !defined(__APPLE__)
    res_init();
 
    for (int i = 0; i < _res.nscount; i ++)
@@ -430,7 +509,7 @@ std::vector<NetworkAccessPoint> CNetwork
    if (!IsWireless())
       return result;
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    // Query the wireless extentsions version number. It will help us when we
    // parse the resulting events
    struct iwreq iwr;
@@ -616,7 +695,7 @@ void CNetworkInterfaceLinux::GetSettings
    encryptionMode = ENC_NONE;
    assignment = NETWORK_DISABLED;
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    FILE* fp = fopen("/etc/network/interfaces", "r");
    if (!fp)
    {
@@ -692,7 +771,7 @@ void CNetworkInterfaceLinux::GetSettings
 
 void CNetworkInterfaceLinux::SetSettings(NetworkAssignment& assignment, CStdString& ipAddress, CStdString& networkMask, CStdString& defaultGateway, CStdString& essId, CStdString& key, EncMode& encryptionMode)
 {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    FILE* fr = fopen("/etc/network/interfaces", "r");
    if (!fr)
    {
