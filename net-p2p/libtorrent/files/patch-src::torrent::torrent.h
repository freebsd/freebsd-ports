--- src/torrent/torrent.h.old	Fri Jan  7 22:34:09 2005
+++ src/torrent/torrent.h	Fri Jan  7 22:51:03 2005
@@ -4,6 +4,8 @@
 #include <list>
 #include <torrent/common.h>
 #include <torrent/download.h>
+#include <sys/types.h>
+#include <sys/select.h>
 
 namespace torrent {
 
