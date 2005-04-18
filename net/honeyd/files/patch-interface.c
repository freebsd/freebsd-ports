--- interface.c.orig	Thu Apr 14 16:07:26 2005
+++ interface.c	Thu Apr 14 14:12:35 2005
@@ -64,8 +64,6 @@
 /* Prototypes */
 int pcap_dloff(pcap_t *);
 
-void honeyd_recv_cb(u_char *, const struct pcap_pkthdr *, const u_char *);
-
 static char *interface_expandips(int, char **, int);
 static void interface_recv(int, short, void *);
 static void interface_poll_recv(int, short, void *);
