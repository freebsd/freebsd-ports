Index: programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c
===================================================================
RCS file: /cvs/xorg/xc/programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c,v
retrieving revision 1.54
diff -u -r1.54 radeon_driver.c
--- programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c	15 Jun 2005 23:40:50 -0000	1.54
+++ programs/Xserver/hw/xfree86/drivers/ati/radeon_driver.c	22 Jun 2005 22:37:22 -0000
@@ -2501,6 +2501,7 @@
     case PCI_CHIP_RV370_5464:
         info->IsMobility = TRUE;
     case PCI_CHIP_RV370_5B60:
+    case PCI_CHIP_RV370_5B62:
     case PCI_CHIP_RV370_5B64:
     case PCI_CHIP_RV370_5B65:
         info->ChipFamily = CHIP_FAMILY_RV380;
