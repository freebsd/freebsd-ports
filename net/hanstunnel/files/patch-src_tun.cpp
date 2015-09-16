--- src/tun.cpp.orig	2014-02-07 03:36:31 UTC
+++ src/tun.cpp
@@ -20,7 +20,7 @@
 #include "tun.h"
 #include "exception.h"
 #include "utility.h"
-
+#include <sys/types.h>
 #include <arpa/inet.h>
 #include <netinet/in_systm.h>
 #include <netinet/in.h>
