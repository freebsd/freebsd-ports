--- ./src/mga_driver.c.orig	2009-07-27 22:11:40.000000000 -0700
+++ ./src/mga_driver.c	2010-03-09 17:58:54.163419467 -0800
@@ -388,6 +388,22 @@
 	8192, 0x4000,          /* Memory probe size & offset values */
     },
 
+    /* G200EH */
+    [14] = { 0, 1, 0, 0, 1, 0, 0, 0, new_BARs,
+            (TRANSC_SOLID_FILL | TWO_PASS_COLOR_EXPAND | USE_LINEAR_EXPANSION),
+	{
+	    { 50000, 230000 }, /* System VCO frequencies */
+	    { 50000, 203400 }, /* Pixel VCO frequencies */
+	    { 0, 0 },          /* Video VCO frequencies */
+	    45000,            /* Memory clock */
+	    27050,             /* PLL reference frequency */
+	    0,                 /* Supports fast bitblt? */
+	    MGA_HOST_PCI       /* Host interface */
+	},
+
+	8192, 0x4000,          /* Memory probe size & offset values */
+    },
+
 };
 
 #ifdef XSERVER_LIBPCIACCESS
@@ -415,6 +431,8 @@
 
     MGA_DEVICE_MATCH( PCI_CHIP_MGAG200_WINBOND_PCI, 13 ),
 
+    MGA_DEVICE_MATCH( PCI_CHIP_MGAG200_EH_PCI, 14 ),
+
     { 0, 0, 0 },
 };
 #endif
@@ -433,6 +451,7 @@
     { PCI_CHIP_MGAG200_SE_B_PCI,	"mgag200 SE B PCI" },
     { PCI_CHIP_MGAG200_EV_PCI,	"mgag200 EV Maxim" },
     { PCI_CHIP_MGAG200_WINBOND_PCI,	"mgag200 eW Nuvoton" },
+    { PCI_CHIP_MGAG200_EH_PCI,	"mgag200eH" },
     { PCI_CHIP_MGAG400,		"mgag400" },
     { PCI_CHIP_MGAG550,		"mgag550" },
     {-1,			NULL }
@@ -455,6 +474,8 @@
 	RES_SHARED_VGA },
     { PCI_CHIP_MGAG200_WINBOND_PCI, PCI_CHIP_MGAG200_WINBOND_PCI,
 	RES_SHARED_VGA },
+    { PCI_CHIP_MGAG200_EH_PCI, PCI_CHIP_MGAG200_EH_PCI,
+	RES_SHARED_VGA },
     { PCI_CHIP_MGAG400,	    PCI_CHIP_MGAG400,	RES_SHARED_VGA },
     { PCI_CHIP_MGAG550,	    PCI_CHIP_MGAG550,	RES_SHARED_VGA },
     { -1,			-1,		RES_UNDEFINED }
@@ -889,6 +910,10 @@
                 attrib_no = 13;
                 break;
 
+            case PCI_CHIP_MGAG200_EH_PCI:
+                attrib_no = 14;
+                break;
+
 	    default:
 		return FALSE;
             }
@@ -1112,7 +1137,7 @@
 	OUTREG8(MGAREG_CRTCEXT_DATA, tmp | 0x80);
 
 	/* apparently the G200 IP don't have a BIOS to read */
-	if (pMga->is_G200SE || pMga->is_G200EV || pMga->is_G200WB) {
+	if (pMga->is_G200SE || pMga->is_G200EV || pMga->is_G200WB || pMga->is_G200EH) {
 	    CARD32 MemoryAt0, MemoryAt1, Offset;
 	    CARD32 FirstMemoryVal1, FirstMemoryVal2;
 	    CARD32 SecondMemoryVal1, SecondMemoryVal2;
@@ -1594,6 +1619,7 @@
 	|| (pMga->Chipset == PCI_CHIP_MGAG200_SE_B_PCI);
     pMga->is_G200EV = (pMga->Chipset == PCI_CHIP_MGAG200_EV_PCI);
     pMga->is_G200WB = (pMga->Chipset == PCI_CHIP_MGAG200_WINBOND_PCI);
+    pMga->is_G200EH = (pMga->Chipset == PCI_CHIP_MGAG200_EH_PCI);
 
 #ifdef USEMGAHAL
     if (pMga->chip_attribs->HAL_chipset) {
@@ -2115,6 +2141,7 @@
     case PCI_CHIP_MGAG200_SE_B_PCI:
     case PCI_CHIP_MGAG200_WINBOND_PCI:
     case PCI_CHIP_MGAG200_EV_PCI:
+    case PCI_CHIP_MGAG200_EH_PCI:
     case PCI_CHIP_MGAG400:
     case PCI_CHIP_MGAG550:
 	MGAGSetupFuncs(pScrn);
@@ -2227,6 +2254,7 @@
 	  case PCI_CHIP_MGAG200_SE_B_PCI:
           case PCI_CHIP_MGAG200_WINBOND_PCI:
 	  case PCI_CHIP_MGAG200_EV_PCI:
+      case PCI_CHIP_MGAG200_EH_PCI:
 	    pMga->SrcOrg = 0;
 	    pMga->DstOrg = 0;
 	    break;
@@ -2413,6 +2441,7 @@
 	case PCI_CHIP_MGAG200_SE_B_PCI:
         case PCI_CHIP_MGAG200_WINBOND_PCI:
 	case PCI_CHIP_MGAG200_EV_PCI:
+    case PCI_CHIP_MGAG200_EH_PCI:
 	case PCI_CHIP_MGAG400:
 	case PCI_CHIP_MGAG550:
 	   maxPitch = 4096;
@@ -4316,7 +4345,10 @@
 	    return MODE_BANDWIDTH;
     } else if (pMga->is_G200EV
 	       && (xf86ModeBandwidth(mode, pScrn->bitsPerPixel) > 327)) {
-	return MODE_BANDWIDTH;
+        return MODE_BANDWIDTH;
+    } else if (pMga->is_G200EH
+               && (xf86ModeBandwidth(mode, pScrn->bitsPerPixel) > 375)) {
+        return MODE_BANDWIDTH;
     }
 
     lace = 1 + ((mode->Flags & V_INTERLACE) != 0);
