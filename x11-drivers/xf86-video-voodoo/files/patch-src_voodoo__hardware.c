# Fix fubar code that worked by accident
#
--- src/voodoo_hardware.c.orig	2016-11-25 18:41:04 UTC
+++ src/voodoo_hardware.c
@@ -390,10 +390,10 @@ static int voodoo_find_dac(VoodooPtr pVo
 	device_id = dac_in(pVoo, 2);
 	
 	/* AT&T 20C409 and clones */
-	if(vendor_id == DAC_VENDOR_ATT && DAC_DEVICE_ATT20C409)
+	if(vendor_id == DAC_VENDOR_ATT && device_id == DAC_DEVICE_ATT20C409)
 		return DAC_ID_ATT;
 		
-	if(vendor_id == DAC_VENDOR_TI && DAC_DEVICE_TITVP3409)
+	if(vendor_id == DAC_VENDOR_TI && device_id == DAC_DEVICE_TITVP3409)
 		return DAC_ID_TI;
 		
 	/* ICS5432 doesn't implement the back door. Glide does some
