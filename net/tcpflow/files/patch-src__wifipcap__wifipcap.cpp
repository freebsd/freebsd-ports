--- ./src/wifipcap/wifipcap.cpp.orig	2013-11-18 02:20:51.000000000 +0000
+++ ./src/wifipcap/wifipcap.cpp	2013-11-22 21:47:50.000000000 +0000
@@ -2213,6 +2213,13 @@
 const char *Wifipcap::SetFilter(const char *filter)
 {
     struct bpf_program fp;
+/*
+ * libpcap from FreeBSD 8 does not have PCAP_NETMASK_UNKNOWN
+ * According to pcap_compile(3) a value of 0 can be supplied
+ */
+#ifndef PCAP_NETMASK_UNKNOWN
+#define PCAP_NETMASK_UNKNOWN 0
+#endif
     bpf_u_int32 netp=PCAP_NETMASK_UNKNOWN;
 
     if(pcap_compile(descr,&fp,(char *)filter,0,netp) == -1) { 
