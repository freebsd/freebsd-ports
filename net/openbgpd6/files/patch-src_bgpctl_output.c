--- src/bgpctl/output.c.orig	2020-05-18 19:17:41 UTC
+++ src/bgpctl/output.c
@@ -25,6 +25,8 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include <sys/endian.h>
+
 #include "bgpd.h"
 #include "session.h"
 #include "rde.h"
