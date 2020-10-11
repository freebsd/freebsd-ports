--- drivedb.h.orig	2019-12-28 21:40:37 UTC
+++ drivedb.h
@@ -4,7 +4,7 @@
  * Home page of code is: https://www.smartmontools.org
  *
  * Copyright (C) 2003-11 Philip Williams, Bruce Allen
- * Copyright (C) 2008-19 Christian Franke
+ * Copyright (C) 2008-20 Christian Franke
  *
  * SPDX-License-Identifier: GPL-2.0-or-later
  */
@@ -68,7 +68,7 @@
 /*
 const drive_settings builtin_knowndrives[] = {
  */
-  { "$Id: drivedb.h 5008 2019-12-28 21:40:37Z chrfranke $",
+  { "$Id$",
     "-", "-",
     "This is a dummy entry to hold the SVN-Id of drivedb.h",
     ""
@@ -136,7 +136,7 @@ const drive_settings builtin_knowndrives[] = {
     "-v 228,raw48,Power-off_Retract_Count "
     //  229 Unknown_Attribute
     "-v 230,raw48,Head_Amplitude,HDD "
-    "-v 231,raw48,Temperature_Celsius "
+    "-v 231,raw48,Temperature_Celsius,HDD "
     "-v 232,raw48,Available_Reservd_Space "
     "-v 233,raw48,Media_Wearout_Indicator,SSD "
     //  234-239 Unknown_Attribute
@@ -353,9 +353,10 @@ const drive_settings builtin_knowndrives[] = {
     "-v 206,raw48,Write_Error_Rate"
   },
   { "Crucial/Micron MX500 SSDs",
-    "CT(250|500|1000|2000)MX500SSD[14]", // tested with CT500MX500SSD1/M3CR023,
-      // .../M3CR020, .../M3CR022
-    "M3CR02[0-3]", // Firmware with bogus attribute 197 (see ticket #1227)
+    "CT(250|500|1000|2000)MX500SSD[14]", // tested with CT500MX500SSD1/M3CR020,
+      // .../M3CR022, .../M3CR023, CT1000MX500SSD1/M3CR010, .../M3CR032
+    "M3CR0([012][0-9]|3[0-2])", // Assume FW <= M3CR032 have bogus attribute 197
+      // (tickets #1227, #1311, #1336)
     "This firmware returns bogus raw values in attribute 197",
   //"-v 1,raw48,Raw_Read_Error_Rate "
     "-v 5,raw48,Reallocate_NAND_Blk_Cnt "
@@ -381,7 +382,7 @@ const drive_settings builtin_knowndrives[] = {
     "-v 247,raw48,Host_Program_Page_Count "
     "-v 248,raw48,FTL_Program_Page_Count"
   },
-  { "Crucial/Micron BX/MX1/2/3/500, M5/600, 1100 SSDs",
+  { "Crucial/Micron BX/MX1/2/3/500, M5/600, 11/1300 SSDs",
     "Crucial_CT(128|256|512)MX100SSD1|"// Marvell 88SS9189, tested with Crucial_CT256MX100SSD1/MU01
     "Crucial_CT(200|250|256|500|512|1000|1024)MX200SSD[1346]|" // Marvell 88SS9189, tested with
       // Crucial_CT500MX200SSD1/MU01, Crucial_CT1024MX200SSD1/MU01, Crucial_CT250MX200SSD3/MU01,
@@ -396,7 +397,8 @@ const drive_settings builtin_knowndrives[] = {
       // Crucial_CT1024M550SSD1/MU01, Crucial_CT128M550SSD4/MU02
     "CT(120|240|480)BX300SSD1|" // Silicon Motion SM2258, same attributes as Marvell-based Crucial SSDs,
       // tested with CT240BX300SSD1/M2CR010
-    "CT(120|240|480|960)BX500SSD1|" // Silicon Motion SM2258XT, tested with CT120BX500SSD1/M6CR013
+    "CT(120|240|480|960|[12]000)BX500SSD1|" // Silicon Motion SM2258XT, tested with CT120BX500SSD1/M6CR013,
+      // CT1000BX500SSD1/M6CR030, CT2000BX500SSD1/M6CR030
     "CT(250|500|1000|2000)MX500SSD[14]|" // Silicon Motion SM2258, tested with CT250MX500SSD1/M3CR010
       // CT500MX500SSD1/M3CR010, CT1000MX500SSD1/M3CR010, CT2000MX500SSD1/M3CR010,
       // CT250MX500SSD4/M3CR022 (now handled by above entry)
@@ -407,10 +409,13 @@ const drive_settings builtin_knowndrives[] = {
     "(Micron_)?M510[_-]MTFDDA[KTV](128|256)MAZ|" // tested with M510-MTFDDAK256MAZ/MU01
     "MICRON_M510DC_(EE|MT)FDDAK(120|240|480|800|960)MBP|" // tested with Micron_M510DC_MTFDDAK240MBP/0005
     "(Micron_)?M550[_-]MTFDDA[KTV](064|128|256|512|1T0)MAY|" // tested with M550-MTFDDAK256MAY/MU01
-    "Micron_M600_(EE|MT)FDDA[KTV](128|256|512|1T0)MBF[25Z]?|" // tested with Micron_M600_MTFDDAK1T0MBF/MU01
-    "(Micron_1100_)?MTFDDA[KV](256|512|1T0|2T0)TBN|" // Marvell 88SS1074, tested with
-      // Micron_1100_MTFDDAK256TBN/M0MU020, MTFDDAK256TBN/M0MA020 (OEM)
-    "Micron 1100 SATA (256G|512G|1T|2T)B", // tested with Micron 1100 SATA 256GB/M0DL022
+    "(Micron_M600_)?(EE|MT)FDDA[KTV](128|256|512|1T0)MBF[25Z]?(-.*)?|" // tested with Micron_M600_MTFDDAK1T0MBF/MU01,
+      // MTFDDAK256MBF-1AN1ZABHA/M603
+    "(Micron_1100_)?MTFDDA[KV](256|512|1T0|2T0)TBN(-.*)?|" // Marvell 88SS1074, tested with
+      // Micron_1100_MTFDDAK256TBN/M0MU020, MTFDDAK256TBN/M0MA020 (OEM), MTFDDAV256TBN-1AR15ABHA/HPC0T14
+    "Micron 1100 SATA (256G|512G|1T|2T)B|" // tested with Micron 1100 SATA 256GB/M0DL022
+    "(Micron_1300_)?(EE|MT)FDDA[KV](256|512|1T0|2T0)TDL", // tested with Micron_1300_MTFDDAK256TDL/M5MU000,
+      // Micron_1300_MTFDDAK1T0TDL/M5MU000, MTFDDAK2T0TDL/M5MU030
     "", "",
   //"-v 1,raw48,Raw_Read_Error_Rate "
     "-v 5,raw48,Reallocate_NAND_Blk_Cnt "
@@ -434,17 +439,26 @@ const drive_settings builtin_knowndrives[] = {
     "-v 202,raw48,Percent_Lifetime_Remain "
     "-v 206,raw48,Write_Error_Rate "
     "-v 210,raw48,Success_RAIN_Recov_Cnt "
+    "-v 223,raw48,Unkn_CrucialMicron_Attr " // M6CR030
     "-v 246,raw48,Total_LBAs_Written "
     "-v 247,raw48,Host_Program_Page_Count "
-    "-v 248,raw48,FTL_Program_Page_Count"
+    "-v 248,raw48,FTL_Program_Page_Count "
+    "-v 249,raw48,Unkn_CrucialMicron_Attr " // M6CR030
+  //"-v 250,raw48,Read_Error_Retry_Rate "   // M6CR030
+    "-v 251,raw48,Unkn_CrucialMicron_Attr " // M6CR030
+    "-v 252,raw48,Unkn_CrucialMicron_Attr " // M6CR030
+    "-v 253,raw48,Unkn_CrucialMicron_Attr " // M6CR030
+    "-v 254,raw48,Unkn_CrucialMicron_Attr"  // M6CR030
   },
   // Reference: https://www.micron.com/resource-details/feec878a-265e-49a7-8086-15137c5f9011
   // TN-FD-34: 5100 SSD SMART Implementation
   {
-    "Micron 5100 Pro / 5200 SSDs",
+    "Micron 5100 Pro / 52x0 / 5300 SSDs",
     "(Micron_5100_)?(EE|MT)FDDA[KV](240|480|960|1T9|3T8|7T6)T(BY|CB|CC)|" // Matches both stock and Dell OEM
       // tested with Micron_5100_MTFDDAK3T8TCB/D0MU410, MTFDDAK3T8TCB/D0MU410
-    "(Micron_5200_)?MTFDDAK(480|960|1T9|3T8|7T6)TD(C|D|N)", // tested with Micron_5200_MTFDDAK3T8TDD/D1MU505
+    "(Micron_5200_)?MTFDDAK(480|960|1T9|3T8|7T6)TD(C|D|N)|" // tested with Micron_5200_MTFDDAK3T8TDD/D1MU505
+    "Micron_5210_MTFDDAK(480|960|1T9|3T8|7T6)QDE|" // tested with Micron_5210_MTFDDAK7T6QDE/D2MU804
+    "Micron_5300_MTFDDA[KV](240|480|960|1T9|3T8|7T6)TD[ST]", // tested with Micron_5300_MTFDDAK1T9TDS/D3MU001
     "", "",
   //"-v 1,raw48,Raw_Read_Error_Rate "
   //"-v 5,raw48,Reallocated_Block_Count "
@@ -472,6 +486,7 @@ const drive_settings builtin_knowndrives[] = {
     "-v 211,raw48,Integ_Scan_Complete_Cnt "  // Number of periodic data integrity scans completed
     "-v 212,raw48,Integ_Scan_Folding_Cnt "   // Number of blocks reallocated by integrity scans
     "-v 213,raw48,Integ_Scan_Progress "      // Current is percentage, raw is absolute number of superblocks scanned by the current integrity scan
+    "-v 246,raw48,Total_LBAs_Written "
     "-v 247,raw48,Host_Program_Page_Count "
     "-v 248,raw48,Bckgnd_Program_Page_Cnt"
   },
@@ -670,28 +685,33 @@ const drive_settings builtin_knowndrives[] = {
   },
   { "Phison Driven SSDs", // see MKP_521_Phison_SMART_attribute.pdf
     "BP4 mSATA SSD|" // MyDigital BP4, tested with BP4 mSATA SSD/S8FM06.9
+    "Corsair Force LE200 SSD|" // tested with Corsair Force LE200 SSD/SBFM10, .../SBFM60.9
+    "GIGABYTE GP-GSTFS31((120|240|256|480)G|100T)NTD|" // tested with GIGABYTE GP-GSTFS31120GNTD/SBFM61.3
     "GOODRAM IRIDIUM PRO|" // tested with GOODRAM IRIDIUM PRO/SAFM01.5
     "IR-SSDPR-S25A-(120|240|480|960)|" // Goodram IRIDM, tested with IR-SSDPR-S25A-120/SBFM91.3,
       // IR-SSDPR-S25A-240/SBFM91.2
+    "KINGSTON O(C|M8)P0S3(64|128|256|512)B-A0|" // tested with KINGSTON OCP0S364B-A0/SBFK62A3,
+      // KINGSTON OM8P0S364B-A0/SBFK62A3
     "KINGSTON SEDC400S37(400|480|800|960|1600|1800)G|" // DC400, tested with
       // KINGSTON SEDC400S37480G/SAFM02.[GH], KINGSTON SEDC400S37960G/SAFM32.I
-    "KINGSTON SEDC(450R|500[MR])(480|960|1920|3840)G|" // DC450R, DC500M/R, tested with
+    "KINGSTON SEDC(450R|500[MR])(480|960|1920|3840|7680)G|" // DC450R, DC500M/R, tested with
       // KINGSTON SEDC450R480G/SCEKH3. KINGSTON SEDC500M1920G/SCEKJ2.3,
-      // KINGSTON SEDC500R480G/SCEKJ2.3
+      // KINGSTON SEDC500R480G/SCEKJ2.3, KINGSTON SEDC450R7680G/SCEKH3.4
     "KINGSTON SUV300S37A(120|240|480)G|" // UV300 SSD, tested with KINGSTON SUV300S37A120G/SAFM11.K
     "KINGSTON SKC310S3B?7A960G|" // SSDNow KC310, KINGSTON SKC310S37A960G/SAFM00.r
     "KINGSTON SKC400S37(128G|256G|512G|1T)|" // SSDNow KC400, KINGSTON SKC400S37128G
     "KINGSTON SV310S3(7A|D7|N7A|B7A)960G|" // SSDNow V310
     "KINGSTON SHSS3B?7A(120|240|480|960)G|" // HyperX Savage
-    "KINGSTON  ?SA400S37(120|240|480|960)G|" // Kingston A400 SSD, Phison S11 or
+    "KINGSTON  ?SA400(M8|S37)(120|240|480|960)G|" // Kingston A400 SSD, Phison S11 or
       // Silicon Motion controller (see ticket #801), tested with
       // KINGSTON SA400S37240G/SBFK10D7, KINGSTON SA400S37120G/SBFK71E0, */SBFKB1D1
-      // KINGSTON  SA400S37480G/SBFK10D7 (two spaces)
+      // KINGSTON  SA400S37480G/SBFK10D7 (two spaces), KINGSTON SA400M8240G/SBFK61E1
     "Patriot (Flare|Blast|Blaze|Burst)|" // tested with Patriot Flare/SBFM91.2,
       // Patriot Blast/SAFM11.3, Patriot Blaze/S9FM02, Patriot Burst/SBFM11.2
-    "PNY CS(13|22)11 (120|240|480|960)GB SSD|" // tested with PNY CS1311 120GB SSD/CS131122,
-      // PNY CS2211 240GB SSD/CS221016
-    "SSD Smartbuy (60|120|240)GB|" // SSD Smartbuy 240GB/SBFM91.1
+    "PNY CS(900|1311|2211) (120|240|480|960)GB SSD|" // tested with PNY CS900 120GB SSD/CS900612,
+      // PNY CS900 240GB SSD/CS900613, PNY CS1311 120GB SSD/CS131122, PNY CS2211 240GB SSD/CS221016
+    "SSD Smartbuy (60|64|120|128|240|256|480|512|960|1024|2000)GB|" // PS3111-S11, tested with
+      // SSD Smartbuy 240GB/SBFM91.1, SSD Smartbuy 64GB/SBFM21.1
     "SSD PHISON 256GB PS3110-S10C|" // tested with SSD PHISON 256GB PS3110-S10C/SAFM12.2
     "SSDPR-CX400-(128|256|512|1024)|" // Goodram CX400, tested with SSDPR-CX400-512/SBFM61.3
     "SSM28(128|256|512)GPTCB3B-S11[24]61[123]", // tested with SSM28256GPTCB3B-S112612/SBFM61.2
@@ -822,6 +842,7 @@ const drive_settings builtin_knowndrives[] = {
   { "Indilinx Barefoot_2/Everest/Martini based SSDs",
     "OCZ VERTEX[ -]PLUS|" // tested with OCZ VERTEX-PLUS/3.55, OCZ VERTEX PLUS/3.55
     "OCZ-VERTEX PLUS R2|" // Barefoot 2, tested with OCZ-VERTEX PLUS R2/1.2
+    "OCZ-OCTANE|" // Everest 1, tested with OCZ-OCTANE/1.13
     "OCZ-PETROL|" // Everest 1, tested with OCZ-PETROL/3.12
     "OCZ-AGILITY4|" // Everest 2, tested with OCZ-AGILITY4/1.5.2
     "OCZ-VERTEX4", // Everest 2, tested with OCZ-VERTEX4/1.5
@@ -1184,9 +1205,10 @@ const drive_settings builtin_knowndrives[] = {
   },
   { "Intel 320 Series SSDs", // tested with INTEL SSDSA2CT040G3/4PC10362,
       // INTEL SSDSA2CW160G3/4PC10362, SSDSA2BT040G3/4PC10362, SSDSA2BW120G3A/4PC10362,
-      // INTEL SSDSA2BW300G3D/4PC10362, SSDSA2BW160G3L/4PC1LE04, SSDSA1NW160G3/4PC10362
-    "INTEL SSDSA[12][BCN][WT](040|080|120|160|300|600)G3[ADL]?",
-      // 2B = 2.5" 7mm, 2C = 2.5" 9.5mm, 1N = 1.8" microSATA
+      // INTEL SSDSA2BW300G3D/4PC10362, SSDSA2BW160G3L/4PC1LE04, SSDSA1NW160G3/4PC10362,
+      // INTEL SSDSA2BW160G3H/4PC10365
+    "INTEL SSDSA[12][BCN][WT](040|080|120|160|300|600)G3[ADHL]?",
+      // 2B = 2.5" 7mm, 2C = 2.5" 9.5mm, 1N = 1.8" microSATA, *H = HP OEM
     "", "",
     "-F nologdir "
   //"-v 3,raw16(avg16),Spin_Up_Time "
@@ -1617,14 +1639,21 @@ const drive_settings builtin_knowndrives[] = {
     "-v 227,raw48,Workld_Host_Reads_Perc "
     "-v 228,raw48,Workload_Minutes"
   },
-  { "Kingston SSDNow UV400",
-    "KINGSTON SUV400S37A?(120|240|480|960)G", // KINGSTON SUV400S37120G/0C3J96R9, 
-    "",
-    "",
+  { "Kingston SSDNow UV400/500",
+    "KINGSTON SUV400S37A?(120|240|480|960)G|" // tested with KINGSTON SUV400S37120G/0C3J96R9,
+      // KINGSTON SUV400S37240G/0C3J96R9, KINGSTON SUV400S37240G/0C3K87RA,
+      // KINGSTON SUV400S37120G/0C3K87RA
+    "KINGSTON SUV500(M[8S])?(120|240|480|960)G", // tested with KINGSTON SUV500120G/003056R6,
+      // KINGSTON SUV500240G/003056R6, KINGSTON SUV500480G/003056RI,
+      // KINGSTON SUV500MS120G/003056RA, KINGSTON SUV500MS120G/003056RI,
+      // KINGSTON SUV500M8120G/003056RI
+    "", "",
     // "-v 1,raw48,Raw_Read_Error_Rate "
     // "-v 5,raw16(raw16),Reallocated_Sector_Ct "
     // "-v 9,raw24(raw8),Power_On_Hours "
     // "-v 12,raw48,Power_Cycle_Count "
+    "-v 100,raw48,Unknown_Kingston_Attr "
+    "-v 101,raw48,Unknown_Kingston_Attr "
     "-v 170,raw48,Reserved_Block_Count "
     "-v 171,raw48,Program_Fail_Count "
     "-v 172,raw48,Erase_Fail_Count "
@@ -1644,9 +1673,9 @@ const drive_settings builtin_knowndrives[] = {
     "-v 201,raw48,Unc_Read_Error_Rate "
     // "-v 204,raw48,Soft_ECC_Correction "
     "-v 231,raw48,SSD_Life_Left "
-    // "-v 241,raw48,Total_LBAs_Written "
-    // "-v 242,raw48,Total_LBAs_Read "
-    "-v 250,raw48,Read_Retry_Count "
+    "-v 241,raw48,Host_Writes_GiB "
+    "-v 242,raw48,Host_Reads_GiB "
+    "-v 250,raw48,Read_Retry_Count"
   },
   { "JMicron based SSDs", // JMicron JMF60x
     "Kingston SSDNow V Series [0-9]*GB|" // tested with Kingston SSDNow V Series 64GB/B090522a
@@ -1663,12 +1692,13 @@ const drive_settings builtin_knowndrives[] = {
     "-v 234,raw24/raw24:w01234,Avg/Max_Erase_Count "
     "-v 235,raw24/raw24:w01z23,Good/Sys_Block_Count"
   },
-  { "JMicron based SSDs", // JMicron JMF61x, JMF66x, JMF670
+  { "JMicron/Maxiotek based SSDs", // JMicron JMF61x, JMF66x, JMF670
     "ADATA S596 Turbo|"  // tested with ADATA S596 Turbo 256GB SATA SSD (JMicron JMF616)
-    "ADATA SP600|"  // tested with ADATA SP600/2.4 (JMicron JMF661)
     "ADATA SP310|"  // Premier Pro SP310 mSATA, JMF667, tested with ADATA SP310/3.04
+    "ADATA SP600(NS34)?|" // tested with ADATA SP600/2.4 (JMicron JMF661)
     "ADATA SX930|"  // tested with ADATA SX930/6.8SE
     "APPLE SSD TS(064|128|256|512)C|"  // Toshiba?, tested with APPLE SSD TS064C/CJAA0201
+    "IM2S3138E-(128|256)GM-B|" // ADATA OEM, tested with IM2S3138E-128GM-B/DA002
     "KingSpec KDM-SA\\.51-008GMJ|" // tested with KingSpec KDM-SA.51-008GMJ/1.092.37 (JMF605?)
     "KINGSTON SNV425S2(64|128)GB|"  // SSDNow V Series (2. Generation, JMF618),
                                     // tested with KINGSTON SNV425S264GB/C091126a
@@ -1678,6 +1708,7 @@ const drive_settings builtin_knowndrives[] = {
     "KINGSTON SVP?100S2B?(64|96|128|256|512)G|"  // SSDNow V100/V+100 Series,
       // tested with KINGSTON SVP100S296G/CJR10202, KINGSTON SV100S2256G/D110225a
     "KINGSTON SV200S3(64|128|256)G|" // SSDNow V200 Series, tested with KINGSTON SV200S3128G/E120506a
+    "NT-(64|128|256|512|[12]T)|" // KingSpec NT, MAS0902A-B2C or CS1802A-B2C, tested with NT-512/T191212
     "TOSHIBA THNS128GG4BBAA|"  // Toshiba / Super Talent UltraDrive DX,
                                // tested with Toshiba 128GB 2.5" SSD (built in MacBooks)
     "TOSHIBA THNSNC128GMLJ|" // tested with THNSNC128GMLJ/CJTA0202 (built in Toshiba Protege/Dynabook)
@@ -1714,12 +1745,13 @@ const drive_settings builtin_knowndrives[] = {
   //"-v 241,raw48,Total_LBAs_Written "    // FW SVN423b
   //"-v 242,raw48,Total_LBAs_Read "       // FW SVN423b
   },
-  { "Plextor M3/M5/M6 Series SSDs", // Marvell 88SS9174 (M3, M5S), 88SS9187 (M5P, M5Pro), 88SS9188 (M6M/S),
+  { "Plextor M3/M5/M6/M7 Series SSDs", // Marvell 88SS9174 (M3, M5S), 88SS9187 (M5P, M5Pro), 88SS9188 (M6M/S),
       // tested with PLEXTOR PX-128M3/1.01, PX-128M3P/1.04, PX-256M3/1.05, PX-128M5S/1.02, PX-256M5S/1.03,
       // PX-128M5M/1.05, PX-128M5S/1.05, PX-128M5Pro/1.05, PX-512M5Pro/1.06, PX-256M5P/1.01, PX-128M6S/1.03
       // (1.04/5 Firmware self-test log lifetime unit is bogus, possibly 1/256 hours)
-      // PLEXTOR PX-256M6S+/1.00
-    "PLEXTOR PX-(64|128|256|512|768)M(3P?|5[MPS]|5Pro|6[MS])\\+?",
+      // PLEXTOR PX-256M6S+/1.00, PLEXTOR  PX-128M3/1.00, PLEXTOR PX-128M3/1.07, PLEXTOR PX-128M6V/1.04,
+      // PLEXTOR PX-128M6G-2242/1.01, PLEXTOR PX-512M7VC/1.05
+    "PLEXTOR  ?PX-(64|128|256|512|768)M(3P?|5[MPS]|5Pro|6[GMSV]|7VC)(\\+|-.*)?",
     "", "",
   //"-v 1,raw48,Raw_Read_Error_Rate "
   //"-v 5,raw16(raw16),Reallocated_Sector_Ct "
@@ -1768,17 +1800,19 @@ const drive_settings builtin_knowndrives[] = {
     "MZ7PC(512|256|128|064)HA(GH|FU|DR)-000.*|" // probably PM830, tested with SAMSUNG MZ7PC128HAFU-000L1/CXM04L1Q
     "Samsung SSD 840 (PRO )?Series|" // tested with Samsung SSD 840 PRO Series 128GB/DXM04B0Q,
       // Samsung SSD 840 Series/DXT06B0Q
-    "Samsung SSD 8[456]0 EVO (mSATA |M\\.2 )?((120|250|500|750)G|[12]T)B|" // tested with
+    "Samsung SSD 8[456]0 EVO (mSATA |M\\.2 )?((120|250|500|750)G|[124]T)B|" // tested with
       // Samsung SSD 840 EVO (120|250|500|750)GB/EXT0AB0Q,
       // Samsung SSD 840 EVO (120|250)GB/EXT0BB6Q, 1TB/EXT0BB0Q, 120GB mSATA/EXT41B6Q,
       // Samsung SSD 850 EVO 250GB/EMT01B6Q, Samsung SSD 850 EVO M.2 250GB/EMT21B6Q,
       // Samsung SSD 850 EVO mSATA 120GB/EMT41B6Q, Samsung SSD 850 EVO 2TB/EMT02B6Q,
       // Samsung SSD 860 EVO 250GB/RVT01B6Q, Samsung SSD 860 EVO mSATA 250GB/RVT41B6Q,
       // Samsung SSD 860 EVO 500GB/RVT01B6Q, Samsung SSD 860 EVO mSATA 500GB/RVT41B6Q,
-      // Samsung SSD 860 EVO mSATA 1TB/RVT41B6Q, Samsung SSD 860 EVO 2TB/RVT01B6Q
-    "Samsung SSD 8[56]0 PRO ((128|256|512)G|1T)B|" // tested with Samsung SSD 850 PRO 128GB/EXM01B6Q,
-      // Samsung SSD 850 PRO 1TB/EXM01B6Q, Samsung SSD 860 PRO 256GB/RVM01B6Q,
-      // Samsung SSD 860 PRO 512GB/RVM01B6Q, Samsung SSD 860 PRO 1TB/RVM01B6Q
+      // Samsung SSD 860 EVO mSATA 1TB/RVT41B6Q, Samsung SSD 860 EVO 2TB/RVT01B6Q,
+      // Samsung SSD 860 EVO 4TB/RVT04B6Q
+    "Samsung SSD 8[56]0 PRO ((128|256|512)G|[124]T)B|" // tested with Samsung SSD 850 PRO 128GB/EXM01B6Q,
+      // Samsung SSD 850 PRO 1TB/EXM01B6Q, Samsung SSD 850 PRO 2TB/EXM02B6Q,
+      // Samsung SSD 860 PRO 256GB/RVM01B6Q, Samsung SSD 860 PRO 512GB/RVM01B6Q,
+      // Samsung SSD 860 PRO 1TB/RVM01B6Q
     "SAMSUNG MZ7PA256HMDR-.*|" // PM810 (470 Series), tested with SAMSUNG MZ7PA256HMDR-010H1/AXM07H1Q
     "Samsung SSD 845DC EVO .*|" // Samsung SSD 845DC EVO 960GB/EXT03X3Q
     "SAMSUNG MZ[7M]PC(032|064|128|256|512)HBCD-.*|" // PM830, tested with SAMSUNG MZMPC032HBCD-000L1/CXM12L1Q
@@ -1865,12 +1899,13 @@ const drive_settings builtin_knowndrives[] = {
       // SanDisk SD7SB6S128G1122/X3310000, SanDisk SD7SN6S-512G-1006/X3511006
     "SanDisk SD8S[BN]8U-?((128|256|512)G|1T00)(1122|-1006)|" // X400 (88SS1074), tested with SanDisk SD8SB8U128G1122/X4120000
     "SanDisk SD9S[BN]8W-?((128|256|512)G|[12]T00)1122|" // X600, tested with SanDisk SD9SB8W128G1122/X6107000
+    "SanDisk SDSSDA-((120|240|480)G|[12]T00)|" // Plus, tested with SanDisk SDSSDA-2T00/411040RL
     "SanDisk SDSSDHP[0-9]*G|" // Ultra Plus (88SS9175), tested with SanDisk SDSSDHP128G/X23[01]6RL
     "SanDisk (SDSSDHII|Ultra II )[0-9]*GB?|" // Ultra II (88SS9190/88SS9189), tested with
       // SanDisk SDSSDHII120G/X31200RL, SanDisk Ultra II 960GB/X41100RL
     "SanDisk SDSSDH2(128|256)G|" // SanDisk SDSSDH2128G/X211200
-    "SanDisk SDSSDH3(250|500|1000|1024|2000)G|" // Ultra 3D, tested with SanDisk SDSSDH3250G/X61170RL,
-      // SanDisk SDSSDH3500G/X61110RL, SanDisk SDSSDH31024G/X6107000
+    "SanDisk SDSSDH3((250|500|1000|1024|2000)G| 4T00)|" // Ultra 3D, tested with SanDisk SDSSDH3250G/X61170RL,
+      // SanDisk SDSSDH3500G/X61110RL, SanDisk SDSSDH31024G/X6107000, SanDisk SDSSDH3 4T00/411040RL
     "SanDisk SDSSDXPS?[0-9]*G|" // Extreme II/Pro (88SS9187), tested with SanDisk SDSSDXP480G/R1311,
       // SanDisk SDSSDXPS480G/X21200RL
     "SanDisk SSD PLUS (120|240|480|1000) ?GB|" // Plus (88SS1074), tested with SanDisk SSD PLUS 120 GB/UE3000RL,
@@ -1885,6 +1920,7 @@ const drive_settings builtin_knowndrives[] = {
     "-v 167,raw48,Min_Bad_Block/Die "
     "-v 168,raw48,Maximum_Erase_Cycle "
     "-v 169,raw48,Total_Bad_Block "
+    "-v 170,raw48,Unknown_Marvell_Attr " // SDSSDH3 4T00
     "-v 171,raw48,Program_Fail_Count "
     "-v 172,raw48,Erase_Fail_Count "
     "-v 173,raw48,Avg_Write/Erase_Count "
@@ -1902,7 +1938,7 @@ const drive_settings builtin_knowndrives[] = {
     "-v 234,raw48,Perc_Write/Erase_Ct_BC "
     "-v 241,raw48,Total_Writes_GiB "
     "-v 242,raw48,Total_Reads_GiB "
-  //"-v 243,raw48,Unknown_Attribute "
+    "-v 243,raw48,Unknown_Marvell_Attr "
     "-v 244,raw48,Thermal_Throttle "
     "-v 249,raw48,TLC_NAND_GB_Writes"
   },
@@ -1989,8 +2025,10 @@ const drive_settings builtin_knowndrives[] = {
    "-v 245,raw48,DriveLife_Used% "
  },
   { "Silicon Motion based SSDs",
-    "ADATA (SP550|SU[89]00)|" // tested with ADATA SP550/O0803B5a, ADATA SU800/Q0913A, ADATA SU800/R0427A,
-      // ADATA SU800/R0918B, ADATA SU900/Q0125A, ADATA SU900/Q0710B
+    "ADATA (SP550|SU(65[05]|[89]00))|" // tested with ADATA SP550/O0803B5a, ADATA SU650/S0212B0,
+      // ADATA SU650/V8X01c45, ADATA SU650/V8X21c64, ADATA SU655/V8X01c55, ADATA SU800/Q0913A,
+      // ADATA SU800/R0427A, ADATA SU800/R0918B, ADATA SU900/Q0125A, ADATA SU900/Q0710B
+    "CORSAIR FORCE LX SSD|" // tested with CORSAIR FORCE LX SSD/N0307A
     "CHN mSATAM3 (128|256|512)|" // Zheino M3, tested with CHN mSATAM3 128/Q1124A0
     "CIS 2S M305 (16|32|64|128|256)GB|" // Ceroz M305, tested with CIS 2S M305 64GB/P0316B
     "CT(120|250|500|1000)BX100SSD1|" // Crucial BX100, tested with CT250BX100SSD1/MU02,
@@ -1999,9 +2037,11 @@ const drive_settings builtin_knowndrives[] = {
     "DREVO X1 SSD|" // tested with DREVO X1 SSD/Q0111A
     "Drevo X1 pro (64|128|256)G|" // tested with Drevo X1 pro 64G/Q0303B
     "JAJS500M(120|240|480|960)C-1|" // J&A LEVEN JS500, tested with JAJS500M120C-1/P0614D
-    "KingDian S(280|400) (120|240|480)GB|" // SM2256EN, tested with KingDian S280 120GB/Q0526A,
-      // KingDian S400 120GB/Q0607A
+    "KingDian S100 (32|64)GB|" // SM2244LT, tested with KingDian S100 32GB/0311A
+    "KingDian S(200|280|400) ((60|120|240|480)GB|1TB)|" // SM2256EN, tested with KingDian S200 60GB/R0724A0
+      // KingDian S280 120GB/Q0526A, KingDian S280 1TB/S0509A0, KingDian S400 120GB/Q0607A
     "KingSpec KSD-[PS]A25\\.[1-9]-(016|032|064|128)(MS|SJ)|" // tested with KingSpec KSD-PA25.6-064MS/20140803
+    "KINGSTON SKC600(256|512|1024|2048)G|" // SM2259, tested with KINGSTON SKC600256G/S4500105
     "LITEON LMH-(128|256|512)V2M-.*|" // tested with LITEON LMH-256V2M-11 MSATA 256GB/FM8110C
     "LITEON LCH-(128|256V|512)2S-.*|" // tested with LITEON LCH-256V2S-HP/2C02
     "MKNSSDRE(1TB|2TB|512GB|500GB|256GB|250GB)|" // tested with MKNSSDRE256GB/N1007C
@@ -2010,23 +2050,26 @@ const drive_settings builtin_knowndrives[] = {
     "Patriot P200 ((128|256|512)GB|[12]TB)|" // tested with Patriot P200 256GB/S1022A0
     "R3SL(120|240|480|960)G|" // AMD Radeon SSDs, tested with R3SL240G/P0422C
     "Ramsta SSD S800 (120|240|480)GB|" // SM2258G, tested with Ramsta SSD S800 480GB/RS81V0
+    "SED2QII-LP SATA SSD ((64|128|256|512)GB|[12]TB)|" // ACPI SED2QII-LP, tested with
+      // SED2QII-LP SATA SSD 64GB/S0410A
     "T60|" // KingSpec T60, tested with T60/20151120
     "TCSUNBOW [MX]3 (60|120|240)GB|" // TC-Sunbow M3/X3, tested with TCSUNBOW M3 240GB/R0327B0,
-       // TCSUNBOW X3 120GB/R1211A0
+      // TCSUNBOW X3 120GB/R1211A0
     "TEAM( T253T|L5Lite3)D(120G|240G|480G|1T)|" // Team Group L5Lite 3D, tested with
       // TEAML5Lite3D240G/R0302A0, TEAM T253TD480G/Q0410A
-    "TS((16|32|64|128|256|512)G|1T)(SSD|MSA)(370S?|420[IK]?)|" // Transcend SSD370/420 SATA/mSATA, TS6500,
-      // tested with TS32GMSA370/20140402, TS16GMSA370/20140516, TS64GSSD370/20140516,
-      // TS256GSSD370/N0815B, TS256GSSD370S/N1114H, TS512GSSD370S/N1114H, TS32GSSD420I/N1114H,
-      // TS32GSSD420K/P1225CE
+    "TS((16|32|64|128|256|512)G|1T)(SSD|MSA)(230S?|370S?|420[IK]?)|" // Transcend SSD230/370/420
+      // SATA/mSATA, TS6500, tested with TS128GMSA230S/02J0S86A, TS32GMSA370/20140402,
+      // TS16GMSA370/20140516, TS64GSSD370/20140516, TS256GSSD370/N0815B, TS256GSSD370S/N1114H,
+      // TS512GSSD370S/N1114H, TS32GSSD420I/N1114H, TS32GSSD420K/P1225CE
     "TS(16|32|64|128|512|256)GMTS4[03]0S?|" // TS256GMTS400, TS256GMTS430S/S0423A
-    "TS(120|240)GMTS420|" // Transcend MTS420
+    "TS(120|240)GMTS420S?|" // Transcend MTS420, tested with TS120GMTS420S/R0510A0
     "TS(128G|256G|512G|1T)SSD230S|" // TS128GSSD230S/P1025F8
     "TS(120|240|480|960)GSSD220S|" // TS480GSSD220S/P0520AA
     "TS(16G|32G|64G|128G|256G|512G|1T)MTS800S?|" // MTS800, tested with TS1TMTS800/O1225H1
     "TS(16|32|64)GMSA630|" // MSA630 mSATA SSD, tested with TS32GMSA630/N0113E1
     "TS(32|64|128)GPSD330|" // Transcend PSD SSD, tested with TS64GPSD330/20140121
-    "TS(16|32|64|96|128|256)GSSD630|" // Transcend 630, tested with TS16GSSD630/N0113E1
+    "TS(16|32|64|96|128|256)GSSD(630|360S)|" // Transcend 630/360S, tested with TS16GSSD630/N0113E1,
+      // TS256GSSD360S/R0123A0
     "TS(128G|256G|512G|1T)ESD400K", // Transcend ESD400 Portable, tested with
       // TS256GESD400K/R0605AS (0x2174:0x2000)
     "", "",
@@ -2038,7 +2081,7 @@ const drive_settings builtin_knowndrives[] = {
     "-v 149,raw48,Max_SLC_Erase_Ct "
     "-v 150,raw48,Min_SLC_Erase_Ct "
     "-v 151,raw48,Average_SLC_Erase_Ct "
-    "-v 159,raw48,Unkn_SiliconMotion_Attr " // SU800/R0427A, SU900/Q0710B, TS256GMTS430S/S0423A
+    "-v 159,raw48,DRAM_1_Bit_Error_Count " // KINGSTON SKC600256G/S4500105
     "-v 160,raw48,Uncorrectable_Error_Cnt "
     "-v 161,raw48,Valid_Spare_Block_Cnt "
     "-v 163,raw48,Initial_Bad_Block_Count "
@@ -2063,6 +2106,7 @@ const drive_settings builtin_knowndrives[] = {
   //"-v 198,raw48,Offline_Uncorrectable "
   //"-v 199,raw48,UDMA_CRC_Error_Count "
     "-v 225,raw48,Host_Writes_32MiB " // FW 20140402
+    "-v 231,raw48,SSD_Life_Left " // KINGSTON SKC600256G/S4500105
   //"-v 232,raw48,Available_Reservd_Space "
     "-v 241,raw48,Host_Writes_32MiB "
     "-v 242,raw48,Host_Reads_32MiB "
@@ -2070,6 +2114,7 @@ const drive_settings builtin_knowndrives[] = {
     "-v 246,raw48,SLC_Writes_32MiB "
     "-v 247,raw48,Raid_Recoverty_Ct "
     "-v 248,raw48,Unkn_SiliconMotion_Attr " // ADATA SU900/Q0125A
+    "-v 249,raw48,Unkn_SiliconMotion_Attr " // ADATA SU650/V8X01c45
   //"-v 250,raw48,Read_Error_Retry_Rate " // ADATA SU800/Q0913A
     "-v 251,raw48,Unkn_SiliconMotion_Attr" // ADATA SU800/Q0913A
   },
@@ -2629,8 +2674,8 @@ const drive_settings builtin_knowndrives[] = {
     "ST(1500|2000)LM0(03|04|06|07|10) HN-M[0-9]*RAD",
     "", "", ""
   },
-  { "Seagate Mobile HDD", // tested with ST2000LM007-1R8174/WDZD1BYX
-     //  ST1000LM035-1RK172/ACM1
+  { "Seagate Mobile HDD", // tested with ST1000LM035-1RK172/ACM1,
+     // ST1000LM035-1RK172/ACM2, ST2000LM007-1R8174/SBK2
     "ST(2000LM0(07|09|10)|1000LM03[578])-.*",
     "", "", ""
   },
@@ -2668,7 +2713,9 @@ const drive_settings builtin_knowndrives[] = {
     "",
     "-v 9,halfminutes"
   },
-  { "SAMSUNG SpinPoint N3U-3 (USB, 4KiB LLS)", // tested with HS25YJZ/3AU10-01
+  { "SAMSUNG SpinPoint N3U-3 (USB)", // tested with
+      // SAMSUNG HS25YJZ/3AU10-01 (0x18a5:0x0227, reports 4KiB LPS/LLS. ticket #159),
+      // SAMSUNG HS20YJZ/3AU10-01 (0x04e8:0x2f06, reports 512B sectors, Debian Bug 964032)
     "SAMSUNG HS(122H|2[05]YJ)Z",
     "", "", ""
   },
@@ -3378,10 +3425,11 @@ const drive_settings builtin_knowndrives[] = {
     "", "",
     "-v 22,raw48,Helium_Level"
   },
-  { "WDC HGST Ultrastar He10", // WD white label, tested with
-      // WDC WD80EMAZ-00WJTA0/83.H0A83, WDC WD80EZAZ-11TDBA0/83.H0A83,
-      // WDC WD100EMAZ-00WJTA0/83.H0A83, WDC WD100EZAZ-11TDBA0/83.H0A83
-    "WDC WD(80|100)E[MZ]AZ-.*",
+  { "Western Digital Ultrastar He10/12", // WD white label, tested with
+      // WDC WD80EMAZ-00WJTA0/83.H0A83 (Easystore 0x1058:0x25fb),
+      // WDC WD80EZAZ-11TDBA0/83.H0A83, WDC WD100EMAZ-00WJTA0/83.H0A83,
+      // WDC WD100EZAZ-11TDBA0/83.H0A83, WDC WD120EMAZ-11BLFA0/81.00A81
+    "WDC WD(80|100|120)E[MZ]AZ-.*",
     "", "",
     "-v 22,raw48,Helium_Level"
   },
@@ -3390,6 +3438,11 @@ const drive_settings builtin_knowndrives[] = {
     "", "",
     "-v 22,raw48,Helium_Level"
   },
+  { "Western Digital Ultrastar DC HC530", // tested with WDC  WUH721414ALE6L4/LDGNW07G
+    "WDC  ?WUH721414ALE6L4",
+    "", "",
+    "-v 22,raw48,Helium_Level"
+  },
   { "HGST MegaScale 4000", // tested with HGST HMS5C4040ALE640/MPAOA580
     "HGST HMS5C4040[AB]LE64[01]", // B = DC 4000.B
     "", "", ""
@@ -3433,7 +3486,7 @@ const drive_settings builtin_knowndrives[] = {
     "",
     "-v 9,minutes"
   },
-  { "Toshiba 2.5\" HDD MK..52GSX",
+  { "Toshiba 2.5\" HDD MK..52GSX", // tested with TOSHIBA MK3252GSX/LV010A
     "TOSHIBA MK(80|12|16|25|32)52GSX",
     "", "", ""
   },
@@ -3901,30 +3954,18 @@ const drive_settings builtin_knowndrives[] = {
     "", "",
     "-v 188,raw16 -v 240,msec24hour32"
   },
-  // should be ST4000DM005, ST3000DM008,ST3000DM009,ST2000DM006,ST2000DM007
-  // ST1000DM010, ST500DM009
-  // tested: ST3000DM008-2DM166/CC26
-  { "Seagate Barracuda 3.5", // tested on ST1000DM010-2EP102/Z9ACZM97
-    "ST(4000DM00[45]|3000DM008|3000DM009|2000DM006|2000DM007|1000DM010|500DM009)-.*",
+  { "Seagate Barracuda 7200.14 (AF)", // < 1TB, tested with ST250DM000-1BC141
+    "ST(250|320|500|750)DM00[0-3]-.*",
     "", "",
     "-v 188,raw16 -v 240,msec24hour32"
   },
-  // ST8000DM004, ST6000DM003, ST4000DM004, ST3000DM007, ST2000DM005
-  { "Seagate Barracuda Compute", // tested on ST8000DM004-2CX188/0001
-    "ST(8000DM004|6000DM003|4000DM004|3000DM007|2000DM005)-.*",
+  { "Seagate BarraCuda 3.5", // tested with ST1000DM010-2EP102/Z9ACZM97,
+      // ST2000DM008-2FR102/0001, ST3000DM008-2DM166/CC26, ST4000DM005-2DP166/0001,
+      // ST4000DM006-2G5107/DN02, ST8000DM004-2CX188/0001, ST10000DM0004-1ZC101/DN01
+    "ST(500DM009|1000DM010|2000DM00[5-9]|3000DM00[789]|4000DM00[456]|6000DM00[34]|8000DM00[45]|10000DM0004)-.*",
     "", "",
-    ""
-  },
-  { "Seagate Barracuda Pro", // tested on ST8000DM004-2CX188/0001
-    "ST(8000DM005|6000DM004|4000DM006|2000DM009)-.*",
-    "", "",
     "-v 188,raw16 -v 240,msec24hour32"
   },
-  { "Seagate Barracuda 7200.14 (AF)", // < 1TB, tested with ST250DM000-1BC141
-    "ST(250|320|500|750)DM00[0-3]-.*",
-    "", "",
-    "-v 188,raw16 -v 240,msec24hour32"
-  },
   { "Seagate Desktop HDD.15", // tested with ST4000DM000-1CD168/CC43, ST5000DM000-1FK178/CC44,
       // ST6000DM001-1XY17Z/CC48
     "ST[4568]000DM00[012]-.*",
@@ -4049,6 +4090,7 @@ const drive_settings builtin_knowndrives[] = {
       // ST4000NM0035-1V4107/TNC3
       // ST1000NM0055-1V410C/TN02
       // ST8000NM0055-1RM112/SN04
+      // ST10000NM0156-2AA111/SS05
     "ST([1234568]|10)000NM0[01][0-68][456]-.*", // *[069]4 = 4Kn
     "", "", 
     "-v 188,raw16 -v 240,msec24hour32"
@@ -4068,11 +4110,20 @@ const drive_settings builtin_knowndrives[] = {
     "", "",
     "-v 240,msec24hour32"
   },
-  { "Seagate Exos X14", // ST12000NM0008-2H3101/SN02
-    "ST(14000NM04[24]8|14000NM0(01|25)8|12000NM0(00|24)8|10000NM0(47|56)8)-.*",
+  { "Seagate Exos X14", // tested with ST12000NM0008-2H3101/SN02,
+      // ST12000NM0538-2K2101/CMA2 (OEM?)
+    "ST(14000NM04[24]8|14000NM0(01|25)8|12000NM0(00|24|53)8|10000NM0(47|56)8)-.*",
     "", "",
+    "-v 18,raw48,Unknown_Seagate_Attrib "
     "-v 240,msec24hour32"
   },
+  { "Seagate Exos X16", // tested with X16 ST14000NM001G-2KJ103/SN02,
+      // ST16000NM001G-2KK103/SN02
+    "ST1[46]000NM00[13]G-.*",
+    "", "",
+    "-v 18,raw48,Unknown_Seagate_Attrib "
+    "-v 240,msec24hour32"
+  },
   // new models: ST8000VN0002, ST6000VN0021, ST4000VN000
   //             ST8000VN0012, ST6000VN0031, ST4000VN003
   // tested with ST8000VN0002-1Z8112/ZA13YGNF
@@ -4088,15 +4139,18 @@ const drive_settings builtin_knowndrives[] = {
     "ST(8000NE|[65432]000VN)00[01]1-.*",
     "", "", ""
   },
-  { "Seagate IronWolf", // tested with ST6000VN0033-2EE110/SC60,
-      // ST6000VN0041-2EL11C/SC61, ST12000VN0007-2GS116/SC60, ST12000VN0008-2JH101/SC60
-    "ST(1|2|3|4|6|8|10|12)000VN00(0?[2478]|22|33|41)-.*",
+  { "Seagate IronWolf", // tested with ST3000VN007-2E4166/SC60, ST4000VN008-2DR166/SC60,
+      // ST6000VN0033-2EE110/SC60, ST6000VN0041-2EL11C/SC61, ST8000VN0022-2EL112/SC61,
+      // ST10000VN0004-1ZD101/SC60, ST12000VN0007-2GS116/SC60, ST12000VN0008-2JH101/SC60
+    "ST(1|2|3|4|6|8|10|12)000VN00(0?[2478]|1|22|33|41)-.*",
     "", "", ""
   },
   { "Seagate IronWolf Pro", // tested with ST4000NE0025-2EW107/EN02,
-      // ST8000NE0004-1ZF11G/EN01, ST8000NE0021-2EN112/EN02
-    "ST([24]000NE0025|6000NE0023|8000NE00(04|08|21)|(10|12|14)000NE000[478])-.*",
-    "", "", ""
+      // ST8000NE0004-1ZF11G/EN01, ST8000NE0021-2EN112/EN02, ST16000NE000-2RW103/EN02
+    "ST([24]000NE0025|4000NE001|6000NE0023|8000NE00(04|08|21)|(10|12|14)000NE000[478]|16000NE000)-.*",
+    "", "",
+    "-v 18,raw48,Unknown_Seagate_Attrib " // ST16000NE000
+    "-v 240,msec24hour32"
   },
   { "Seagate Archive HDD", // tested with ST8000AS0002-1NA17Z/AR13
     "ST[568]000AS00[01][12]-.*",
@@ -4143,9 +4197,15 @@ const drive_settings builtin_knowndrives[] = {
   // ST3000VX000, ST3000VX004, ST2000VX000, ST2000VX004, ST1000VX000
   { "Seagate Surveillance", // tested with ST1000VX001-1HH162/CV11, ST2000VX000-9YW164/CV12,
       // ST4000VX000-1F4168/CV14, ST2000VX003-1HH164/CV12
-    "ST([1-6]000VX00[01234]1?|31000526SV|3500411SV)(-.*)?",
+    "ST([1-5]000VX00[01234]1?|31000526SV|3500411SV)(-.*)?",
     "", "", ""
   },
+  { "Seagate Skyhawk", // tested with ST3000VX010-2H916L/CV11, ST6000VX0023-2EF110/SC60
+    "ST(1000VX005|2000VX008|3000VX0(09|10)|4000VX007|6000VX00(1|23)|8000VX00(4|22))-.*",
+    "", "",
+    "-v 9,msec24hour32 " // CV* Firmware only?
+    "-v 240,msec24hour32"
+  },
   { "Seagate DB35", // tested with ST3250823ACE/3.03, ST3300831SCE/3.03
     "ST3(200826|250823|300831|400832)[AS]CE",
     "", "", ""
@@ -4242,13 +4302,17 @@ const drive_settings builtin_knowndrives[] = {
     "-v 242,raw48,Lifetime_Rds_Frm_Hst_GB "
     "-v 243,hex56,Free_Space "
   },
-  { "WD Blue and Green SSDs", // tested with WDC WDS250G1B0A-00H9H0/X41000WD,
+  { "WD Blue / Red / Green SSDs", // tested with WDC WDS250G1B0A-00H9H0/X41000WD,
       // WDC WDS250G1B0A-00H9H0/X41100WD, WDC WDS100T1B0A-00H9H0,
       // WDC WDS120G2G0A-00JH30/UE360000, WDC WDS240G2G0A-00JH30/UF300000,
       // WDC WDS500G2B0A-00SM50/X61130WD, WDC WDS200T2B0A-00SM50/X61130WD,
       // WDC WDS200T2B0A/X61190WD, WDC WDS120G1G0A-00SS50/Z3311000
-      // WDC  WDS500G2B0A-00SM50/401000WD
-    "WDC  ?WDS((120|240|250|480|500)G|[12]00T)(1B|2B|1G|2G)0[AB](-.*)?", // *B* = Blue, *G* = Green, *2B* = Blue 3D NAND
+      // WDC  WDS500G2B0A-00SM50/401000WD,
+      // WDC WDBNCE2500PNC/X61130WD, WDC WDBNCE0010PNC-WRSN/X41110WD,
+      // WDC  WDS200T1R0A-68A4W0/411000WR
+    "WDC WDBNCE(250|500|00[124])0PNC(-.*)?|" // Blue 3D
+    "WDC  ?WDS((120|240|250|480|500)G|[12]00T)(1B|2B|1G|2G|1R)0[AB](-.*)?",
+      // *B* = Blue, *G* = Green, *2B* = Blue 3D NAND, *1R* = Red SA500
     "", "",
   //"-v 5,raw48,Reallocated_Sector_Ct " // Reassigned Block Count
   //"-v 9,raw48,Power_On_Hours "
@@ -4379,6 +4443,10 @@ const drive_settings builtin_knowndrives[] = {
     "WDC WD((25|32|50)00AAKX|5000AZ(LX|RZ)|7500A(AL|ZE)X|10E(AL|ZE)X|[1-6]0EZRZ)-.*",
     "", "", ""
   },
+  { "Western Digital Blue (SMR)", // ticket #1313
+    "WDC WD(20|60)EZAZ-.*",
+    "", "", ""
+  },
   { "Western Digital RE Serial ATA",
     "WDC WD(12|16|25|32)00(SD|YD|YS)-.*",
     "", "", ""
@@ -4391,8 +4459,9 @@ const drive_settings builtin_knowndrives[] = {
     "WDC WD(5000AB|7500AY|1000FY)PS-.*",
     "", "", ""
   },
-  { "Western Digital RE3 Serial ATA", // tested with WDC WD7502ABYS-02A6B0/03.00C06
-    "WDC WD((25|32|50|75)02A|(75|10)02F)BYS-.*",
+  { "Western Digital RE3 Serial ATA", // tested with WDC WD7502ABYS-02A6B0/03.00C06,
+       // WD1002FBYS-12/03.M0300
+    "(WDC )?WD((25|32|50|75)02A|(75|10)02F)BYS-.*",
     "", "", ""
   },
   { "Western Digital RE4", // tested with WDC WD2003FYYS-18W0B0/01.01D02,
@@ -4435,8 +4504,8 @@ const drive_settings builtin_knowndrives[] = {
   { "Western Digital Green", // tested with
       // WDC WD10EZRX-00A8LB0/01.01A01, WDC WD20EZRX-00DC0B0/80.00A80,
       // WDC WD30EZRX-00MMMB0/80.00A80, WDC WD40EZRX-00SPEB0/80.00A80,
-      // WDC WD60EZRX-00MVLB1/80.00A80
-    "WDC WD(7500AA|(10|15|20)EA|(10|20|25|30|40|50|60)EZ)RX-.*",
+      // WDC WD60EZRX-00MVLB1/80.00A80, WDC WD5000AZRX-00A8LB0/01.01A01
+    "WDC WD(5000AZ|7500AA|(10|15|20)EA|(10|20|25|30|40|50|60)EZ)RX-.*",
     "", "", ""
   },
   { "Western Digital Caviar Black", // tested with WDC WD7501AAES/06.01D06
@@ -4457,6 +4526,10 @@ const drive_settings builtin_knowndrives[] = {
     // old series: WD4001FAEX WD3001FAEX WD2002FAEX WD1002FAEX  WD5003AZEX
     "", "", ""
   },
+  { "Western Digital Black (SMR)", // ticket #1313
+    "WDC WD10SPSX-.*",
+    "", "", ""
+  },
   { "Western Digital AV ATA", // tested with WDC WD3200AVJB-63J5A0/01.03E01
     "WDC WD(8|16|25|32|50)00AV[BJ]B-.*",
     "", "", ""
@@ -4528,34 +4601,49 @@ const drive_settings builtin_knowndrives[] = {
       // WDC WD40EFRX-68WT0N0/80.00A80, WDC WD60EFRX-68MYMN1/82.00A82,
       // WDC WD80EFAX-68LHPN0/83.H0A83, WDC WD80EFZX-68UW8N0/83.H0A83,
       // WDC WD80EZZX-11CSGA0/83.H0A03 (My Book 0x1058:0x25ee),
-      // WDC WD60EFAX-68SHWN0/82.00A82, WDC WD100EFAX-68LHPN0/83.H0A83
-    "WDC WD(7500BFC|10JFC|[1-6]0EFR|[68]0E[FZ][AZ]|100EFA)X-.*",
+      // WDC WD100EFAX-68LHPN0/83.H0A83,
+      // WDC WD120EMFZ-11A6JA0/81.00A81 (Easystore 0x1058:0x25fb)
+    "WDC WD(7500BFCX|10JFCX|[1-6]0EFRX|[68]0E[FZ]ZX|(8|10)0EFAX|120EMFZ)-.*",
     "", "",
-    "-v 22,raw48,Helium_Level" // WD80EFZX, WD100EFAX
+    "-v 22,raw48,Helium_Level" // WD80EFAX, WD80EFZX, WD100EFAX, WD120EMFZ
   },
+  { "Western Digital Red (SMR)", // ticket #1313, tested with WDC WD60EFAX-68SHWN0/82.00A82
+    "WDC WD[2346]0EFAX-.*",
+    "", "", ""
+  },
   { "Western Digital Red Pro", // tested with WDC WD2001FFSX-68JNUN0/81.00A81,
       // WDC WD6002FFWX-68TZ4N0/83.H0A83, WDC WD101KFBX-68R56N0/83.H0A03
     "WDC WD([2-68]00[123]FF[BSW]|101KFB)X-.*",
     "", "",
     "-v 22,raw48,Helium_Level" // WD101KFBX
   },
-  { "Western Digital Purple", // tested with WDC WD40PURX-64GVNY0/80.00A80
-    "WDC WD[123456]0PURX-.*",
+  { "Western Digital Purple", // tested with WDC WD40PURX-64GVNY0/80.00A80,
+      // WDC WD40PURZ-85TTDY0/80.00A80
+      // WDC WD80PUZX-64NEAY0/80.H0A80
+    "WDC WD[1234568]0PU[RZ][XZ]-.*",
     "", "", ""
   },
   { "Western Digital Gold", // tested with WDC WD1005FBYZ-01YCBB2/RR07,
       // WDC WD2005FBYZ-01YCBB2/RR07, WDC WD4002FYYZ-01B7CB0/01.01M02,
-      // WDC WD8003FRYZ-01JPDB1/01.01H02, WDC WD121KRYZ-01W0RB0/01.01H01
-    "WDC WD([12]005FB|4002FY|6002FR|800[23]FR|1[02]1KR)YZ-.*",
+      // WDC WD4003FRYZ-01F0DB0/01.01H01, WDC WD6003FRYZ-01F0DB0/01.01H01,
+      // WDC WD8003FRYZ-01JPDB1/01.01H02, WDC WD8004FRYZ-01VAEB0/01.01H01,
+      // WDC WD102KRYZ-01A5AB0/01.01H01, WDC WD121KRYZ-01W0RB0/01.01H01
+    "WDC WD([12]005FB|4002FY|4003FR|600[23]FR|800[234]FR|(1[02]1|102)KR)YZ-.*",
     "", "",
     "-v 22,raw48,Helium_Level" // WD121KRYZ
   },
-  { "Western Digital Blue", // tested with WDC WD5000LPVX-08V0TT2/03.01A03,
-      // WDC WD20NPVZ-00WFZT0/01.01A01
-      // WDC WD10SPZX-22Z10T0/01.01A01
-    "WDC WD(20SPZX|20NPVZ|15NPVZ|10[SJ]PZX|7500BPVX|5000[BL]PVX|5000LPCX|3200LPCX)-.*",
-    "", "", ""
+  { "Western Digital Blue Mobile", // tested with WDC WD5000LPVX-08V0TT2/03.01A03,
+       // WDC WD10JPVX-75JC3T0/0301A03,  WDC WD10JPVX-22JC3T0/01.01A01,
+       // WDC WD20NPVZ-00WFZT0/01.01A01
+    "WDC WD(3200LPCX|5000[BL]P[CV]X|7500BPVX|10JP[VZ]X|(15|20)NPVZ)-.*",
+     "", "", ""
   },
+  { "Western Digital Blue Mobile (SMR)", // ticket #1313, tested with
+       // WDC WD10SPZX-22Z10T0/01.01A01, WDC WD10SPZX-21Z10T0/02.01A02,
+       // WDC WD20SPZX-22CRAT0/01.01A01, WDC WD20SPZX-22UA7T0/01.01A01
+    "WDC WD[12]0SPZX-.*",
+     "", "", ""
+  },
   { "Western Digital Green Mobile", // tested with WDC WD20NPVX-00EA4T0/01.01A01
     "WDC WD(15|20)NPV[TX]-.*",
     "", "", ""
@@ -4577,6 +4665,7 @@ const drive_settings builtin_knowndrives[] = {
       // WDC WD10JMVW-11AJGS2/01.01A01 (0x1058:0x10b8),
       // WDC WD10JMVW-11AJGS4/01.01A01 (0x1058:0x25a0/25a2),
       // WDC WD10JMVW-11S5XS1/01.01A01,
+      // WDC WD10SMZW-11Y0TS0/01.01A01,
       // WDC WD10TMVW-11ZSMS5/01.01A01,
       // WDC WD20NMVW-11AV3S2/01.01A01 (0x1058:0x0822),
       // WDC WD20NMVW-11AV3S3/01.01A01 (0x1058:0x0837),
@@ -4586,7 +4675,8 @@ const drive_settings builtin_knowndrives[] = {
       // WDC WD20NMVW-59AV3S3/01.01A01 (0x1058:0x107d),
       // WDC WD30NMVW-11C3NS4/01.01A01,
       // WDC WD40NMZW-11GX6S1/01.01A01 (0x1058:0x2599/25e2/25fa)
-    "WDC WD(5000[LK]|7500[BK]|10[JT]|[234]0N)M[VZ][VW]-.*", // *W-* = USB 3.0
+      // WDC WD50NDZW-11MR8S1/02.01A02
+    "WDC WD((5000[LK]|7500[BK]|10[JST]|[234]0N)M|50ND)[VZ][VW]-.*", // *W-* = USB 3.0
     "", "", ""
   },
   { "Quantum Bigfoot", // tested with TS10.0A/A21.0G00, TS12.7A/A21.0F00
@@ -4785,8 +4875,8 @@ const drive_settings builtin_knowndrives[] = {
     "",
     "-d usbjmicron" // 0x1f0a: works also with "-d sat"
   },
-  { "USB: Samsung S1 Portable; JMicron",
-    "0x04e8:0x2f03",
+  { "USB: Samsung S1; JMicron",
+    "0x04e8:0x2f0[36]", // 0x2f03: S1 Portable, 0x2f06: S1 Mini (SAMSUNG HS20YJZ/3AU10-01)
     "",
     "",
     "-d usbjmicron"
@@ -5170,6 +5260,13 @@ const drive_settings builtin_knowndrives[] = {
     "",
     "-d sat"
   },
+  // 0x0860 (?)
+  { "USB: ; ",
+    "0x0860:0x0001",
+    "", // 0x0100
+    "",
+    "-d sat"
+  },
   // Oxford Semiconductor, Ltd
   { "USB: ; Oxford",
     "0x0928:0x0000",
@@ -5214,6 +5311,12 @@ const drive_settings builtin_knowndrives[] = {
     "",
     "-d sat"
   },
+  { "USB: Toshiba; Sunplus",
+    "0x0930:0xa002",
+    "", // 0x0103
+    "",
+    "-d usbsunplus"
+  },
   // Lumberg, Inc.
   { "USB: Toshiba Stor.E; Sunplus",
     "0x0939:0x0b1[56]",
@@ -5229,9 +5332,9 @@ const drive_settings builtin_knowndrives[] = {
   },
   // Apricorn
   { "USB: Apricorn SATA Wire; ",
-    "0x0984:0x0040",
+    "0x0984:0x0(040|301)", // 0x0040: Apricorn SATA Wire
+    "", // 0x0301 (0x0201): Corsair SSD & HDD Cloning Kit
     "",
-    "",
     "-d sat"
   },
   // Neodio Technologies
@@ -5260,6 +5363,13 @@ const drive_settings builtin_knowndrives[] = {
     "",
     "-d sat"
   },
+  // Realtek
+  { "USB: ; Realtek RTL9210", // USB->PCIe (NVMe)
+    "0x0bda:0x9210",
+    "", // 0x2100
+    "",
+    "-d sntrealtek"
+  },
   // Addonics
   { "USB: Addonics HDMU3; ", // (ticket #609)
     "0x0bf6:0x1001",
@@ -5386,9 +5496,9 @@ const drive_settings builtin_knowndrives[] = {
   },
   // ADATA
   { "USB: ADATA; ",
-    "0x125f:0xa(11|13|15|31|35|37|75)a", // 0xa11a: Classic CH11 1TB, 0xa13a: NH13 1TB,
+    "0x125f:0xa(11|13|15|31|35|37|75|83)a", // 0xa11a: Classic CH11 1TB, 0xa13a: NH13 1TB,
     "", // 0xa15a: HD710 1TB, 0xa31a: HV620 2TB (0x0100), 0xa35a: HD650 2TB (0x6503),
-    "", // 0xa37a: Silverstone MS10 M.2 (0x3103), 0xa75a: HD710P 4TB
+    "", // 0xa37a: Silverstone MS10 M.2 (0x3103), 0xa75a: HD710P 4TB, 0xa83a: HD330 (0x0100)
     "-d sat"
   },
   { "USB: ADATA; Cypress",
@@ -5491,6 +5601,12 @@ const drive_settings builtin_knowndrives[] = {
     "",
     "" // unsupported
   },
+  { "USB: ; JMicron",
+    "0x152d:0x1337",
+    "", // 0x0508, Digitus DA-71106
+    "",
+    "-d sat"
+  },
   { "USB: ; JMicron JMS561", // USB2/3->2xSATA
     "0x152d:0x[19]561", // 0x1561(0x0106), Sabrent USB 3.0 Dual Bay SATA Dock
     "",  // 0x9561(0x0105), Orico 6629US3-C USB 3.0 Dual Bay SATA Dock
@@ -5639,7 +5755,7 @@ const drive_settings builtin_knowndrives[] = {
     "",
     "-d usbsunplus"
   },
-  { "USB: Verbatim Pocket Hard Drive; JMicron", // SAMSUNG SpinPoint N3U-3 (USB, 4KiB LLS)
+  { "USB: Verbatim Pocket Hard Drive; JMicron", // SAMSUNG HS25YJZ/3AU10-01
     "0x18a5:0x0227",
     "",
     "",
@@ -5704,6 +5820,12 @@ const drive_settings builtin_knowndrives[] = {
     "",
     "-d sat"
   },
+  { "USB: OWC Mercury Elite Pro Quad; ",
+    "0x1e91:0xa4a7",
+    "", // 0x0100
+    "",
+    "-d sat"
+  },
   // Innostor
   { "USB: ; Innostor IS611", // USB3->SATA+PATA
     "0x1f75:0x0611", // SMART access via PATA does not work
@@ -5752,6 +5874,13 @@ const drive_settings builtin_knowndrives[] = {
   // 0x2537 (?)
   { "USB: ; ", // USB 3.0
     "0x2537:0x106[68]", // 0x1066: Orico 2599US3, 0x1068: Fantec ER-35U3
+    "", // 0x0100
+    "",
+    "-d sat"
+  },
+  // AKiTiO (?)
+  { "USB: AkiTio NT2 U3.1C; ",
+    "0x2ce5:0x0014",
     "", // 0x0100
     "",
     "-d sat"
