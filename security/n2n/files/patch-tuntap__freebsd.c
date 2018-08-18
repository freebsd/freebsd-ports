--- tuntap_freebsd.c.orig	2018-08-18 08:16:29 UTC
+++ tuntap_freebsd.c
@@ -20,7 +20,7 @@
 
 #ifdef __FreeBSD__
 
-void tun_close(tuntap_dev *device);
+void tuntap_close(tuntap_dev *device);
 
 /* ********************************** */
 
@@ -78,7 +78,7 @@ int tuntap_open(tuntap_dev *device /* ignored */, 
 
     fd = popen(buf, "r");
     if(fd < 0) {
-      tun_close(device);
+      tuntap_close(device);
       return(-1);
     } else {
       int a, b, c, d, e, f;
