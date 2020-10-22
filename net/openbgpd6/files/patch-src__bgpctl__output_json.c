--- src/bgpctl/output_json.c.orig	2020-05-18 19:17:41 UTC
+++ src/bgpctl/output_json.c
@@ -22,6 +22,8 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include <sys/endian.h>
+
 #include "bgpd.h"
 #include "session.h"
 #include "rde.h"
