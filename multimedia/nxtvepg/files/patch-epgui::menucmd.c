--- epgui/menucmd.c.orig	Sat Nov 30 14:46:44 2002
+++ epgui/menucmd.c	Sun Jan  5 23:41:49 2003
@@ -2312,7 +2312,7 @@
    }
    else
    {
-      #ifdef __NetBSD__
+      #if defined(__NetBSD__) || defined(__FreeBSD__)
       // On NetBSD BtDriver_GetCardName fetches its data from a struct which is filled here
       BtDriver_ScanDevices(TRUE);
       #endif
