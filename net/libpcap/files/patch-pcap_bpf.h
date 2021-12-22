--- pcap/bpf.h.orig	2021-06-07 20:21:35 UTC
+++ pcap/bpf.h
@@ -78,6 +78,10 @@
  */
 #if !defined(_NET_BPF_H_) && !defined(_NET_BPF_H_INCLUDED) && !defined(_BPF_H_) && !defined(_H_BPF) && !defined(lib_pcap_bpf_h)
 #define lib_pcap_bpf_h
+#define _NET_BPF_H_
+#define _NET_BPF_H_INCLUDED
+#define _BPF_H_
+#define _H_BPF
 
 #include <pcap/funcattrs.h>
 
