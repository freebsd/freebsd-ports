--- src/drivers.c.orig	Sat May 18 11:48:47 2002
+++ src/drivers.c	Sat May 18 11:50:28 2002
@@ -554,7 +554,6 @@
     if(!devname || (devname && !strcmp(devname, tempndata.ifmd_name))) {
       ndev = malloc(sizeof(struct Devices));
       ndev->devstart = 0;
-      ndev->if_index = i;
       ndev->name = strdup(tempndata.ifmd_name);
       ndata = malloc(sizeof(struct ifmibdata));
       bcopy (&tempndata, ndata, sizeof(struct ifmibdata));
@@ -596,7 +595,7 @@
   datamib[4] = 1; /* fill in later */
   datamib[5] = IFDATA_GENERAL;
 
-  datamib[4] = dev->if_index;
+  datamib[4] = IFMIB_IFCOUNT;
 
   len = sizeof(struct ifmibdata); 
 
