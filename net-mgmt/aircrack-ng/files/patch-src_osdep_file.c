--- src/osdep/file.c.orig	2018-01-11 15:45:35 UTC
+++ src/osdep/file.c
@@ -33,7 +33,7 @@
 #include <err.h>
 
 #include "osdep.h"
-#include "pcap.h"
+#include "../pcap.h"
 #include "radiotap/radiotap_iter.h"
 
 struct priv_file {
