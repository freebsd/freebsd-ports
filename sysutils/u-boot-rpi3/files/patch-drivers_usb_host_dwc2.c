--- drivers/usb/host/dwc2.c.orig	2018-03-13 12:02:19 UTC
+++ drivers/usb/host/dwc2.c
@@ -1283,6 +1283,7 @@ struct dm_usb_ops dwc2_usb_ops = {
 
 static const struct udevice_id dwc2_usb_ids[] = {
 	{ .compatible = "brcm,bcm2835-usb" },
+	{ .compatible = "brcm,bcm2708-usb" },
 	{ .compatible = "snps,dwc2" },
 	{ }
 };
