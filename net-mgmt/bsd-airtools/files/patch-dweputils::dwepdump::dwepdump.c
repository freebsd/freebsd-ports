--- dweputils/dwepdump/dwepdump.c.orig	Sat Jul  6 15:24:30 2002
+++ dweputils/dwepdump/dwepdump.c	Sat Jul  6 15:24:45 2002
@@ -46,7 +46,7 @@
 #include <errno.h>
 
 #include <pcap.h>
-#include <bat/common.h>
+#include <dev/wi/if_wavelan_ieee.h>
 
 /*
  * definitions
