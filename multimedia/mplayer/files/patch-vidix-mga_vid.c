--- vidix/mga_vid.c.orig	2007-10-08 03:49:27.000000000 +0800
+++ vidix/mga_vid.c	2007-10-20 16:24:47.000000000 +0800
@@ -1110,13 +1110,10 @@
 		    i, lst[i].vendor, lst[i].device);
 	    if (lst[i].vendor == VENDOR_MATROX)
 	    {
-#if 0
 		if ((lst[i].command & PCI_COMMAND_IO) == 0)
 		{
-			printf("[mga] Device is disabled, ignoring\n");
-			continue;
+			printf("[mga] Device is disabled, trying anyways.\n");
 		}
-#endif
 		switch(lst[i].device)
 		{
 		    case DEVICE_MATROX_MGA_G550_AGP:
