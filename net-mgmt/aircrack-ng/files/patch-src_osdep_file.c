--- src/aircrack-osdep/file.c.orig
+++ src/aircrack-osdep/file.c
@@ -33,7 +33,7 @@
 #include <err.h>
 
 #include "osdep.h"
-#include "pcap.h"
+#include "../pcap.h"
 #include "radiotap/radiotap_iter.h"
 
 struct priv_file {
