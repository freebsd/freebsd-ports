# Correct the type of a few variables
#
--- src/glint_driver.c.orig	2017-01-17 22:34:15 UTC
+++ src/glint_driver.c
@@ -1326,8 +1326,8 @@ GLINTPreInit(ScrnInfoPtr pScrn, int flag
 		    int basecopro = 
 			PCI_REGION_BASE(pGlint->MultiPciInfo[0], 0, REGION_MEM) & 0xFFFFC000;
 		    int basedelta = PCI_REGION_BASE(pGlint->PciInfo, 0, REGION_MEM)  & 0xFFFFC000;
-		    int dummy;
-		    int base3copro, offset;
+		    uint32_t dummy;
+		    uint32_t base3copro, offset;
 
     		    if( (basedelta & 0x20000) ^ (basecopro & 0x20000) ) {
  			if ((pGlint->MultiChip == PCI_CHIP_3DLABS_PERMEDIA) ||
