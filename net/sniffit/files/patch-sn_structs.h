--- sn_structs.h.orig	Sat Aug 16 09:12:03 2003
+++ sn_structs.h	Sat Aug 16 09:12:17 2003
@@ -67,7 +67,7 @@
 struct snif_mask                                         /* struct for mask */
   {
   _32_bit source_ip, destination_ip;
-  _32_bit short source_port, destination_port;
+  _32_bit source_port, destination_port;
   };
 
 /* (packet generation) */
