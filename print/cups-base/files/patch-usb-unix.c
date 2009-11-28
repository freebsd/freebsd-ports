--- backend/usb-unix.c.orig	2009-08-31 20:45:43.000000000 +0200
+++ backend/usb-unix.c	2009-10-21 09:21:14.000000000 +0200
@@ -36,7 +36,7 @@
  */
 
 static int	open_device(const char *uri, int *use_bc);
-static int	side_cb(int print_fd, int device_fd, int snmp_fd,
+static void	side_cb(int print_fd, int device_fd, int snmp_fd,
 		        http_addr_t *addr, int use_bc);
 
 
@@ -579,7 +579,7 @@
   datalen = sizeof(data);
 
   if (cupsSideChannelRead(&command, &status, data, &datalen, 1.0))
-    return (-1);
+    return;
 
   switch (command)
   {
@@ -622,7 +622,8 @@
 	break;
   }
 
-  return (cupsSideChannelWrite(command, status, data, datalen, 1.0));
+  cupsSideChannelWrite(command, status, data, datalen, 1.0);
+  return;
 }
 
 
