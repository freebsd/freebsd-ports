--- src/belle_sip_internal.h.orig	2015-10-19 11:43:47 UTC
+++ src/belle_sip_internal.h
@@ -23,6 +23,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <errno.h>
+#include <netinet/in.h>
 
 /* include all public headers*/
 #include "belle-sip/belle-sip.h"
