--- ./xbmc/network/linux/NetworkLinux.cpp.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/network/linux/NetworkLinux.cpp	2012-01-02 10:14:38.000000000 +0100
@@ -23,18 +23,26 @@
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
 #include <ifaddrs.h>
+#include <net/route.h>
+/* Darwin doesn't define this for some very odd reason */
+#ifndef SA_SIZE
+# define SA_SIZE(sa)						\
+	(  (!(sa) || ((struct sockaddr *)(sa))->sa_len == 0) ?	\
+	   sizeof(long)		:				\
+	   1 + ( (((struct sockaddr *)(sa))->sa_len - 1) | (sizeof(long) - 1) ) )
+#endif
 #else
 #include <net/if_arp.h>
 #endif
@@ -64,7 +72,7 @@
 
 bool CNetworkInterfaceLinux::IsWireless()
 {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   return false;
 #else
   struct iwreq wrq;
@@ -144,7 +152,7 @@
 {
    CStdString result = "";
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    char essid[IW_ESSID_MAX_SIZE + 1];
    memset(&essid, 0, sizeof(essid));
 
@@ -166,7 +174,48 @@
 {
    CStdString result = "";
 
-#ifndef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
+   size_t needed;
+   int mib[6];
+   char *buf, *next, *lim;
+   char line[16];
+   struct rt_msghdr *rtm;
+   struct sockaddr *sa;
+   struct sockaddr_in *sockin;
+
+   mib[0] = CTL_NET;
+   mib[1] = PF_ROUTE;
+   mib[2] = 0;
+   mib[3] = 0;
+   mib[4] = NET_RT_DUMP;
+   mib[5] = 0;
+   if (sysctl(mib, 6, NULL, &needed, NULL, 0) < 0)
+      return result;
+
+   if ((buf = (char *)malloc(needed)) == NULL)
+      return result;
+
+   if (sysctl(mib, 6, buf, &needed, NULL, 0) < 0) {
+      free(buf);
+      return result;
+   }
+
+   lim  = buf + needed;
+   for (next = buf; next < lim; next += rtm->rtm_msglen) {
+      rtm = (struct rt_msghdr *)next;
+      sa = (struct sockaddr *)(rtm + 1);
+      sa = (struct sockaddr *)(SA_SIZE(sa) + (char *)sa);	
+      sockin = (struct sockaddr_in *)sa;
+      if (inet_ntop(AF_INET, &sockin->sin_addr.s_addr,
+         line, sizeof(line)) == NULL) {
+            free(buf);
+            return result;
+	  }
+	  result = line;
+      break;
+   }
+   free(buf);
+#else
    FILE* fp = fopen("/proc/net/route", "r");
    if (!fp)
    {
@@ -267,7 +316,7 @@
 CStdString CNetworkLinux::GetMacAddress(CStdString interfaceName)
 {
   CStdString result = "00:00:00:00:00:00";
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 
 #if ! defined(IFT_ETHER)
 #define IFT_ETHER 0x6/* Ethernet CSMACD */
@@ -333,7 +382,7 @@
   CStdString macAddr = "";
   m_interfaces.clear();
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 
    // Query the list of interfaces.
    struct ifaddrs *list;
@@ -430,7 +479,7 @@
    if (!IsWireless())
       return result;
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    // Query the wireless extentsions version number. It will help us when we
    // parse the resulting events
    struct iwreq iwr;
@@ -616,7 +665,7 @@
    encryptionMode = ENC_NONE;
    assignment = NETWORK_DISABLED;
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    FILE* fp = fopen("/etc/network/interfaces", "r");
    if (!fp)
    {
@@ -692,7 +741,7 @@
 
 void CNetworkInterfaceLinux::SetSettings(NetworkAssignment& assignment, CStdString& ipAddress, CStdString& networkMask, CStdString& defaultGateway, CStdString& essId, CStdString& key, EncMode& encryptionMode)
 {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    FILE* fr = fopen("/etc/network/interfaces", "r");
    if (!fr)
    {
