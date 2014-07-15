--- src/belle_sip_internal.h.orig	2014-06-30 16:50:46.873520744 +0600
+++ src/belle_sip_internal.h	2014-06-30 16:51:05.264521071 +0600
@@ -23,6 +23,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <errno.h>
+#include <netinet/in.h>
 
 /* include all public headers*/
 #include "belle-sip/belle-sip.h"
