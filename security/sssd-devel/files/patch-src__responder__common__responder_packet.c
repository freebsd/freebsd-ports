--- src/responder/common/responder_packet.c.orig	2023-05-05 08:11:07 UTC
+++ src/responder/common/responder_packet.c
@@ -25,6 +25,7 @@
 #include <errno.h>
 #include <talloc.h>
 
+#include "util/sss_bsd_errno.h"
 #include "util/util.h"
 #include "responder/common/responder_packet.h"
 
