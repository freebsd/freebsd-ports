--- src/lldp_port.h.orig	Sun Apr  1 02:27:04 2007
+++ src/lldp_port.h	Wed Jun 27 16:49:17 2007
@@ -21,6 +21,7 @@
    
    Used to iterate through the interface list.
 */ 
+#define MIN_INTERFACES   1
 #define MAX_INTERFACES 254
 
 /** 
