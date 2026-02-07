--- libs-external/USI++/usi++/tcp.h.orig	2005-07-27 08:38:14 UTC
+++ libs-external/USI++/usi++/tcp.h
@@ -12,6 +12,8 @@
 #ifndef _TCP_H_
 #define _TCP_H_
 
+#include <cstring>
+
 #include "usi-structs.h"
 #include "datalink.h"
 #include "ip.h"
