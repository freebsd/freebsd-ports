--- backend/usb.c.orig	Thu May 16 09:44:50 2002
+++ backend/usb.c	Thu Aug  8 11:37:20 2002
@@ -433,18 +433,7 @@
 #elif defined(__sun)
 #elif defined(__hpux)
 #elif defined(__osf)
-#elif defined(__FreeBSD__)
-  int   i;                      /* Looping var */
-  char  device[255];            /* Device filename */
-
-
-  for (i = 0; i < 3; i ++)
-  {
-    sprintf(device, "/dev/unlpt%d", i);
-    if (!access(device, 0))
-      printf("direct usb:%s \"Unknown\" \"USB Printer #%d\"\n", device, i + 1);
-  }
-#elif defined(__NetBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
   int   i;                      /* Looping var */
   char  device[255];            /* Device filename */
 
