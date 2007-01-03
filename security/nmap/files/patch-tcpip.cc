--- tcpip.cc.orig	Fri Dec  8 04:01:19 2006
+++ tcpip.cc	Wed Jan  3 17:15:05 2007
@@ -133,6 +133,8 @@
 #endif /* NETINET_IF_ETHER_H */
 #endif /* HAVE_NETINET_IF_ETHER_H */
 
+#include <sys/param.h>
+
 extern NmapOps o;
 
 #ifdef WIN32
@@ -1959,7 +1961,7 @@
 
 // Returns whether the system supports pcap_get_selectable_fd() properly
 bool pcap_selectable_fd_valid() {
-#if defined(WIN32) || defined(MACOSX)
+#if defined(WIN32) || defined(MACOSX) || (defined(FREEBSD) && (__FreeBSD_version < 500000))
   return false;
 #endif
   return true;
@@ -1972,7 +1974,7 @@
    results.  If you just want to test whether the function is supported,
    use pcap_selectable_fd_valid() instead. */
 int my_pcap_get_selectable_fd(pcap_t *p) {
-#if defined(WIN32) || defined(MACOSX)
+#if defined(WIN32) || defined(MACOSX) || (defined(FREEBSD) && (__FreeBSD_version < 500000))
   return -1;
 #else
   assert(pcap_selectable_fd_valid());
