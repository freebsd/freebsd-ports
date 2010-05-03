--- src/i830_dvo.c.orig	2010-05-03 11:09:54.000000000 -0500
+++ src/i830_dvo.c	2010-05-03 11:13:31.000000000 -0500
@@ -38,28 +38,6 @@
 #include "ch7xxx/ch7xxx.h"
 #include "tfp410/tfp410.h"
 
-static const char *SIL164Symbols[] = {
-    "Sil164VidOutput",
-    NULL
-};
-static const char *TFP410Symbols[] = {
-    "Tfp410VidOutput",
-    NULL
-};
-static const char *CH7xxxSymbols[] = {
-    "CH7xxxVidOutput",
-    NULL
-};
-static const char *ivch_symbols[] = {
-    "ivch_methods",
-    NULL
-};
-
-static const char *ch7017_symbols[] = {
-    "ch7017_methods",
-    NULL
-};
-
 /* driver list */
 struct _I830DVODriver i830_dvo_drivers[] =
 {
@@ -69,7 +47,6 @@
 	.fntablename = "SIL164VidOutput",
 	.dvo_reg = DVOC,
 	.address = (SIL164_ADDR_1<<1),
-	.symbols = SIL164Symbols
     },
     {
 	.type = I830_OUTPUT_DVO_TMDS,
@@ -77,7 +54,6 @@
 	.fntablename = "CH7xxxVidOutput",
 	.dvo_reg = DVOC,
 	.address = (CH7xxx_ADDR_1<<1),
-	.symbols = CH7xxxSymbols
     },
     {
 	.type = I830_OUTPUT_DVO_LVDS,
@@ -85,7 +61,6 @@
 	.fntablename = "ivch_methods",
 	.dvo_reg = DVOA,
 	.address = 0x04, /* Might also be 0x44, 0x84, 0xc4 */
-	.symbols = ivch_symbols
     },
     {
 	.type = I830_OUTPUT_DVO_TMDS,
@@ -93,7 +68,6 @@
 	.fntablename = "TFP410VidOutput",
 	.dvo_reg = DVOC,
 	.address = (TFP410_ADDR_1<<1),
-	.symbols = TFP410Symbols
     },
     {
 	.type = I830_OUTPUT_DVO_LVDS,
@@ -101,7 +75,6 @@
 	.fntablename = "ch7017_methods",
 	.dvo_reg = DVOC,
 	.address = 0xea,
-	.symbols = ch7017_symbols,
 	.gpio = GPIOE,
     }
 };
@@ -447,8 +420,6 @@
 	if (drv->modhandle == NULL)
 	    continue;
 
-	xf86LoaderReqSymLists(drv->symbols, NULL);
-
 	ret_ptr = NULL;
 	drv->vid_rec = LoaderSymbol(drv->fntablename);
 
