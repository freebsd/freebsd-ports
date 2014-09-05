--- vidix/mga_vid.c.orig	2014-05-17 03:38:00.000000000 +0200
+++ vidix/mga_vid.c	2014-08-11 20:58:07.109876980 +0200
@@ -1110,13 +1110,10 @@
 		    i, lst[i].vendor, lst[i].device);
 	    if (lst[i].vendor == VENDOR_MATROX)
 	    {
-#if 0
 		if ((lst[i].command & PCI_COMMAND_IO) == 0)
 		{
-			mp_msg(MSGT_VO, MSGL_STATUS, "[mga] Device is disabled, ignoring\n");
-			continue;
+			mp_msg(MSGT_VO, MSGL_STATUS, "[mga] Device seems disabled, trying anyway\n");
 		}
-#endif
 		switch(lst[i].device)
 		{
 		    case DEVICE_MATROX_MGA_G550_AGP:
