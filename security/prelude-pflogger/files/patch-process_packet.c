--- src/process_packet.c.orig	2012-04-11 12:08:57.000000000 -0500
+++ src/process_packet.c	2012-04-11 12:05:26.000000000 -0500
@@ -43,10 +43,10 @@
 #include <net/if_pflog.h>
 #include <net/pfvar.h>
 #include <netdb.h>
+#include <net/bpf.h>
 #include <pcap.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
-#include <net/bpf.h>
 #include <errno.h>
 
 #include <libprelude/prelude.h>
