--- honeyd.h.orig	Thu Apr 14 16:07:26 2005
+++ honeyd.h	Thu Apr 14 14:30:27 2005
@@ -32,6 +32,8 @@
 #ifndef _HONEYD_H_
 #define _HONEYD_H_
 
+#include <pcap.h>
+
 #define PIDFILE			"/var/run/honeyd.pid"
 
 #define TCP_DEFAULT_SIZE	512
@@ -300,6 +302,8 @@
 char *honeyd_contoa(const struct tuple *);
 
 void honeyd_input(const struct interface *, struct ip_hdr *, u_short);
+
+void honeyd_recv_cb(u_char *, const struct pcap_pkthdr *, const u_char *);
 
 /* Command prototypes for services */
 void cmd_droppriv(uid_t, gid_t);
