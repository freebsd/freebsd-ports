--- vidix/mga_vid.c.orig	2014-05-17 01:38:00 UTC
+++ vidix/mga_vid.c
@@ -1110,13 +1110,10 @@ static int mga_probe(int verbose,int for
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
