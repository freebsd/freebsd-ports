--- server/drivers/port.h.orig	Tue Jan 18 20:04:12 2005
+++ server/drivers/port.h	Tue Jan 18 20:04:29 2005
@@ -64,7 +64,7 @@
 
 // Write a byte 'val' to port
 static inline void port_out (unsigned short int port, unsigned char val) {
-	outb(val, port);
+#	outb(val, port);
 }
 
 // Get access to a specific port
@@ -91,7 +91,7 @@
 
 // Write a byte 'val' to port
 static inline void port_out (unsigned short int port, unsigned char val) {
-	outb(port, val);
+#	outb(port, val);
 }
 
 static inline void setaccess(u_long * map, u_int bit, int allow) {
