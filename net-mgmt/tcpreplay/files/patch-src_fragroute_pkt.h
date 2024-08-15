--- src/fragroute/pkt.h.orig	2023-12-31 18:39:02 UTC
+++ src/fragroute/pkt.h
@@ -8,9 +8,9 @@
 
 #pragma once
 
+#include "lib/queue.h"
 #include "defines.h"
 #include "config.h"
-#include "lib/queue.h"
 #include <sys/time.h>
 
 #ifdef HAVE_LIBDNET
