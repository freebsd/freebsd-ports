--- src/belle_sip_internal.h.orig	2022-05-18 04:20:06 UTC
+++ src/belle_sip_internal.h
@@ -25,6 +25,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <errno.h>
+#include <netinet/in.h>
 
 /* include all public headers*/
 #include "belle-sip/belle-sip.h"
