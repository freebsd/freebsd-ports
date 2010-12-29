--- ./xbmc/linux/NetworkLinux.cpp.orig	2010-03-06 18:18:26.000000000 +0100
+++ ./xbmc/linux/NetworkLinux.cpp	2010-12-01 12:17:34.260943458 +0100
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
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/sockio.h>
 #include <net/if.h>
 #include <ifaddrs.h>
@@ -40,6 +40,9 @@
 #include "NetworkLinux.h"
 #include "Util.h"
 #include "log.h"
+#if defined(__FreeBSD__)
+#include <net/route.h>
+#endif
 
 using namespace std;
 
@@ -61,7 +64,7 @@
 
 bool CNetworkInterfaceLinux::IsWireless()
 {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   return false;
 #else
   struct iwreq wrq;
@@ -106,7 +109,7 @@
 {
    CStdString result = "";
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
    result.Format("00:00:00:00:00:00");
 #else
    struct ifreq ifr;
@@ -160,7 +163,7 @@
 {
    CStdString result = "";
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    char essid[IW_ESSID_MAX_SIZE + 1];
    memset(&essid, 0, sizeof(essid));
 
@@ -182,7 +185,84 @@
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
@@ -262,7 +342,7 @@
 {
    m_interfaces.clear();
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 
    // Query the list of interfaces.
    struct ifaddrs *list;
@@ -280,7 +360,6 @@
    }
 
    freeifaddrs(list);
-
 #else
    FILE* fp = fopen("/proc/net/dev", "r");
    if (!fp)
@@ -327,7 +406,7 @@
 std::vector<CStdString> CNetworkLinux::GetNameServers(void)
 {
    std::vector<CStdString> result;
-#ifndef __APPLE__
+#if !defined(__APPLE__)
    res_init();
 
    for (int i = 0; i < _res.nscount; i ++)
@@ -363,7 +442,7 @@
    if (!IsWireless())
       return result;
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    // Query the wireless extentsions version number. It will help us when we
    // parse the resulting events
    struct iwreq iwr;
@@ -549,7 +628,7 @@
    encryptionMode = ENC_NONE;
    assignment = NETWORK_DISABLED;
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    FILE* fp = fopen("/etc/network/interfaces", "r");
    if (!fp)
    {
@@ -625,7 +704,7 @@
 
 void CNetworkInterfaceLinux::SetSettings(NetworkAssignment& assignment, CStdString& ipAddress, CStdString& networkMask, CStdString& defaultGateway, CStdString& essId, CStdString& key, EncMode& encryptionMode)
 {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    FILE* fr = fopen("/etc/network/interfaces", "r");
    if (!fr)
    {
