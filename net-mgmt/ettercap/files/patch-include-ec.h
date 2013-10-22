--- include/ec.h.orig	2013-09-12 04:18:45.000000000 +0800
+++ include/ec.h	2013-10-22 03:14:56.006394661 +0800
@@ -12,6 +12,8 @@
 #include <stdbool.h>
 #include <stdlib.h>
 
+#include <net/bpf.h>
+
 #ifdef OS_WINDOWS
    #include <windows.h>
 #endif
