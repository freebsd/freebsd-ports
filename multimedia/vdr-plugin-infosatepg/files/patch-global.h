--- a/global.h
+++ b/global.h
@@ -9,8 +9,10 @@
 #ifndef __global_h_
 #define __global_h_
 
+#include <sys/socket.h>
 #include <netinet/if_ether.h>
 #include <sys/types.h>
+#include <ctype.h>
 
 #include <vdr/channels.h>
 #include <vdr/timers.h>
@@ -162,7 +164,7 @@ public:
         return directory;
     }
     bool SetDirectory (const char *Directory);
-    bool CheckMAC (struct ethhdr *eth_hdr);
+    bool CheckMAC (ether_header *eth_hdr);
     void SetWaitTimer()
     {
         timer=time (NULL);
