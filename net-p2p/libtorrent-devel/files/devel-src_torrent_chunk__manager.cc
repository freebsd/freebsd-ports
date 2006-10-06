--- src/torrent/chunk_manager.cc.orig	Fri Oct  6 18:59:46 2006
+++ src/torrent/chunk_manager.cc	Fri Oct  6 19:00:09 2006
@@ -37,6 +37,7 @@
 #include "config.h"
 
 #include <sys/types.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 
 #include "data/chunk_list.h"
