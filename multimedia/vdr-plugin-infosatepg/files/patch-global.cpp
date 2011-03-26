--- a/global.cpp
+++ b/global.cpp
@@ -164,7 +164,11 @@ cGlobalInfosatepg::cGlobalInfosatepg()
     MAC[3]=0x02;
     MAC[4]=0x02;
     WaitTime=10; // default 10 seconds
+#ifdef __FreeBSD__
+    SetDirectory ("/var/cache/vdr/infosatepg");
+#else
     SetDirectory ("/tmp");
+#endif
     NoWakeup=false;
     NoDeferredShutdown=false;
     ActualMac=0;
@@ -194,17 +198,17 @@ bool cGlobalInfosatepg::SetDirectory(con
     return true;
 }
 
-bool cGlobalInfosatepg::CheckMAC(struct ethhdr *eth_hdr)
+bool cGlobalInfosatepg::CheckMAC(ether_header *eth_hdr)
 {
     if (!eth_hdr) return false;
-    if (eth_hdr->h_dest[0]!=MAC[0]) return false;
-    if (eth_hdr->h_dest[1]!=MAC[1]) return false;
-    if (eth_hdr->h_dest[2]!=MAC[2]) return false;
-    if (eth_hdr->h_dest[3]!=MAC[3]) return false;
-    if (eth_hdr->h_dest[4]!=MAC[4]) return false;
+    if (eth_hdr->ether_dhost[0]!=MAC[0]) return false;
+    if (eth_hdr->ether_dhost[1]!=MAC[1]) return false;
+    if (eth_hdr->ether_dhost[2]!=MAC[2]) return false;
+    if (eth_hdr->ether_dhost[3]!=MAC[3]) return false;
+    if (eth_hdr->ether_dhost[4]!=MAC[4]) return false;
 
-    if (eth_hdr->h_dest[5]<EPG_FIRST_DAY_MAC) return false;
-    if (eth_hdr->h_dest[5]>EPG_LAST_DAY_MAC) return false;
+    if (eth_hdr->ether_dhost[5]<EPG_FIRST_DAY_MAC) return false;
+    if (eth_hdr->ether_dhost[5]>EPG_LAST_DAY_MAC) return false;
 
     return true;
 }
