--- src/utils/net/ip.ml.orig	Sun Jan 30 16:45:11 2005
+++ src/utils/net/ip.ml	Sun Jan 30 16:45:17 2005
@@ -84,7 +84,7 @@
   j > 0 && j < 224 && 
   k >= 0 && k <= 255 && 
   l >= 0 && l <= 255 &&
-  i >= 0 && i <= 255
+  i > 0 && i <= 255
   
 let reachable ip = 
   !allow_local_network ||
