--- src/main.c.orig	2013-07-14 13:20:52.000000000 +0200
+++ src/main.c	2013-07-15 08:18:16.497236179 +0200
@@ -901,8 +901,13 @@
   snprintf(path, sizeof(path),  "/sys/class/%s/device/speed", dev);
 
   if(readlinefromfile(path, l, sizeof(l))) {
+#if defined(PLATFORM_FREEBSD)
+    // Assume USB2.0 on FreeBSD because there are no supported PCI devices
+    return HOSTCONNECTION_USB480;
+#else
     // Unable to read speed, assume it's PCI
     return HOSTCONNECTION_PCI;
+#endif
   } else {
     speed = atoi(l);
    
