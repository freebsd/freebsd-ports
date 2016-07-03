--- packetsource_pcap.cc.orig	2016-07-02 18:06:10 UTC
+++ packetsource_pcap.cc
@@ -22,6 +22,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <time.h>
+#include <net/bpf.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
