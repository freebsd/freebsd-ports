--- src/wmwifi.c.orig	Sat Jul  2 14:54:17 2005
+++ src/wmwifi.c	Sat Jul  2 14:54:21 2005
@@ -67,6 +67,7 @@
     int ncolor = 0;
     struct wifi wfi;
 
+    bzero(&wfi, sizeof(wfi));
 	/* find a valid wireless interface */
 #if __FreeBSD__
 	wfi.ifnum = get_wlaniface(0, 1);
