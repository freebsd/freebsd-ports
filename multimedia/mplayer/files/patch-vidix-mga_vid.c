--- vidix/mga_vid.c.orig	2009-05-12 21:58:57.000000000 -0500
+++ vidix/mga_vid.c	2009-07-23 20:41:50.683011307 -0500
@@ -1110,13 +1110,10 @@
 		    i, lst[i].vendor, lst[i].device);
 	    if (lst[i].vendor == VENDOR_MATROX)
 	    {
-#if 0
 		if ((lst[i].command & PCI_COMMAND_IO) == 0)
 		{
-			printf("[mga] Device is disabled, ignoring\n");
-			continue;
+                        printf("[mga] Device is disabled, trying anyways.\n");
 		}
-#endif
 		switch(lst[i].device)
 		{
 		    case DEVICE_MATROX_MGA_G550_AGP:
