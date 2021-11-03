--- drivedb.h.orig	2021-10-19 20:02:57 UTC
+++ drivedb.h
@@ -4,7 +4,7 @@
  * Home page of code is: https://www.smartmontools.org
  *
  * Copyright (C) 2003-11 Philip Williams, Bruce Allen
- * Copyright (C) 2008-20 Christian Franke
+ * Copyright (C) 2008-21 Christian Franke
  *
  * SPDX-License-Identifier: GPL-2.0-or-later
  */
@@ -68,9 +68,9 @@
 /*
 const drive_settings builtin_knowndrives[] = {
  */
-  { "$Id: drivedb.h 5150 2020-12-29 16:55:11Z chrfranke $",
+  { "VERSION: 7.3 $Id: drivedb.h 5236 2021-09-14 13:17:47Z chrfranke $",
     "-", "-",
-    "This is a dummy entry to hold the SVN-Id of drivedb.h",
+    "Version information",
     ""
   },
   { "DEFAULT",
@@ -441,8 +441,8 @@ const drive_settings builtin_knowndrives[] = {
     "(Micron_1100_)?MTFDDA[KV](256|512|1T0|2T0)TBN(-.*)?|" // Marvell 88SS1074, tested with
       // Micron_1100_MTFDDAK256TBN/M0MU020, MTFDDAK256TBN/M0MA020 (OEM), MTFDDAV256TBN-1AR15ABHA/HPC0T14
     "Micron 1100 SATA (256G|512G|1T|2T)B|" // tested with Micron 1100 SATA 256GB/M0DL022
-    "(Micron_1300_)?(EE|MT)FDDA[KV](256|512|1T0|2T0)TDL", // tested with Micron_1300_MTFDDAK256TDL/M5MU000,
-      // Micron_1300_MTFDDAK1T0TDL/M5MU000, MTFDDAK2T0TDL/M5MU030
+    "(Micron_1300_)?(EE|MT)FDDA[KV](256|512|1T0|2T0)TDL(-.*)?", // tested with Micron_1300_MTFDDAK256TDL/M5MU000,
+      // Micron_1300_MTFDDAK1T0TDL/M5MU000, MTFDDAK2T0TDL/M5MU030, MTFDDAK256TDL-1AW1ZABFA/M5MA030
     "", "",
   //"-v 1,raw48,Raw_Read_Error_Rate "
     "-v 5,raw48,Reallocate_NAND_Blk_Cnt "
@@ -1070,18 +1070,19 @@ const drive_settings builtin_knowndrives[] = {
     "-v 248,raw48,Remaining_Life "
     "-v 249,raw48,Spare_Blocks_Remaining"
   },
-  { "Innodisk 3IE3/3ME3/3ME4 SSDs", // tested with 2.5" SATA SSD 3ME3/S15A19, CFast 3ME3/S15A19
+  { "Innodisk 1IE3/3IE3/3ME3/3IE4/3ME4 SSDs", // tested with 2.5" SATA SSD 3ME3/S15A19,
       // InnoDisk Corp. - mSATA 3ME3/S15A19, mSATA mini 3ME3/S15A19, M.2 (S42) 3ME3,
       // SATA Slim 3ME3/S15A19, SATADOM-MH 3ME3/S15A19, SATADOM-ML 3ME3/S15A19,
       // SATADOM-MV 3ME3/S15A19, SATADOM-SL 3ME3/S15A19, SATADOM-SV 3ME3/S15A19,
       // SATADOM-SL 3IE3/S151019N, 2.5" SATA SSD 3IE3/S15C14i, CFast 3IE3/S15C14i,
-      // InnoDisk Corp. - mSATA 3IE3/S15C14i, Mini PCIeDOM 1IE3/S15C14i,
+      // InnoDisk Corp. - mSATA 3IE3/S15C14i, Mini PCIeDOM 1IE3/S15C14i, CFast 3ME3/S15A19
       // mSATA mini 3IE3/S15C14i, M.2 (S42) 3IE3/S15C14i, SATA Slim 3IE3/S15C14i,
       // SATADOM-SH 3IE3 V2/S15C14i, SATADOM-SL 3IE3 V2/S15A19i, SATADOM-SV 3IE3 V2/S15C14i
       // mSATA 3ME4/L16711, M.2 (S42) 3ME4/L16711, SATADOM-MH 3ME4/L16B01,
-      // SATADOM-SH 3ME4/L16B01, SATADOM-SH Type C 3ME4/L16B01, SATADOM-SH Type D 3ME4/L16B01
+      // SATADOM-SH 3ME4/L16B01, SATADOM-SH Type C 3ME4/L16B01, SATADOM-SH Type D 3ME4/L16B01,
+      // mSATA 3IE4/L16B01Hi
     "(2.5\" SATA SSD|CFast|InnoDisk Corp\\. - mSATA|Mini PCIeDOM|mSATA( mini)?|"
-    "M\\.2 \\(S42\\)|SATA Slim|SATADOM-[MS][HLV]( Type [CD])?) 3([IM]E3|ME4)( V2)?",
+    "M\\.2 \\(S42\\)|SATA Slim|SATADOM-[MS][HLV]( Type [CD])?) (1IE3|3[IM]E[34])( V2)?",
     "", "",
   //"-v 1,raw48,Raw_Read_Error_Rate "
   //"-v 2,raw48,Throughput_Performance "
@@ -1828,7 +1829,7 @@ const drive_settings builtin_knowndrives[] = {
     "MZ7PC(512|256|128|064)HA(GH|FU|DR)-000.*|" // probably PM830, tested with SAMSUNG MZ7PC128HAFU-000L1/CXM04L1Q
     "Samsung SSD 840 (PRO )?Series|" // tested with Samsung SSD 840 PRO Series 128GB/DXM04B0Q,
       // Samsung SSD 840 Series/DXT06B0Q
-    "Samsung SSD 8[456]0 EVO (mSATA |M\\.2 )?((120|250|500|750)G|[124]T)B|" // tested with
+    "Samsung SSD 8[4-7]0 EVO (mSATA |M\\.2 )?((120|250|500|750)G|[124]T)B|" // tested with
       // Samsung SSD 840 EVO (120|250|500|750)GB/EXT0AB0Q,
       // Samsung SSD 840 EVO (120|250)GB/EXT0BB6Q, 1TB/EXT0BB0Q, 120GB mSATA/EXT41B6Q,
       // Samsung SSD 850 EVO 250GB/EMT01B6Q, Samsung SSD 850 EVO M.2 250GB/EMT21B6Q,
@@ -1836,23 +1837,25 @@ const drive_settings builtin_knowndrives[] = {
       // Samsung SSD 860 EVO 250GB/RVT01B6Q, Samsung SSD 860 EVO mSATA 250GB/RVT41B6Q,
       // Samsung SSD 860 EVO 500GB/RVT01B6Q, Samsung SSD 860 EVO mSATA 500GB/RVT41B6Q,
       // Samsung SSD 860 EVO mSATA 1TB/RVT41B6Q, Samsung SSD 860 EVO 2TB/RVT01B6Q,
-      // Samsung SSD 860 EVO 4TB/RVT04B6Q
+      // Samsung SSD 860 EVO 4TB/RVT04B6Q, Samsung SSD 870 EVO 1TB/SVT01B6Q
     "Samsung SSD 8[56]0 PRO ((128|256|512)G|[124]T)B|" // tested with Samsung SSD 850 PRO 128GB/EXM01B6Q,
       // Samsung SSD 850 PRO 1TB/EXM01B6Q, Samsung SSD 850 PRO 2TB/EXM02B6Q,
       // Samsung SSD 860 PRO 256GB/RVM01B6Q, Samsung SSD 860 PRO 512GB/RVM01B6Q,
       // Samsung SSD 860 PRO 1TB/RVM01B6Q
-    "Samsung SSD 883 DCT (240|480|960)GB|" // tested with Samsung SSD 883 DCT 480GB/HXT7404Q
-    "SAMSUNG MZ7PA256HMDR-.*|" // PM810 (470 Series), tested with SAMSUNG MZ7PA256HMDR-010H1/AXM07H1Q
+    "Samsung SSD 8[67]0 QVO [1248]TB|" // tested with Samsung SSD 860 QVO 1TB/RVQ02B6Q,
+      // Samsung SSD 860 QVO 2TB/RVQ01B6Q, Samsung SSD 870 QVO 4TB/SVQ01B6Q
+    "Samsung SSD 883 DCT ((240|480|960)G|(1\\.92|3\\.84)T)B|" // tested with
+      // Samsung SSD 883 DCT 480GB/HXT7404Q, Samsung SSD 883 DCT 3.84TB/HXT7404Q
     "Samsung SSD 845DC EVO .*|" // Samsung SSD 845DC EVO 960GB/EXT03X3Q
-    "Samsung SSD 870 QVO [1248]TB|" // tested with Samsung SSD 870 QVO 4TB/SVQ01B6Q
+    "SAMSUNG MZ7PA256HMDR-.*|" // PM810 (470 Series), tested with SAMSUNG MZ7PA256HMDR-010H1/AXM07H1Q
     "SAMSUNG MZ[7M]PC(032|064|128|256|512)HBCD-.*|" // PM830, tested with SAMSUNG MZMPC032HBCD-000L1/CXM12L1Q
     "SAMSUNG MZ7TD(128|256)HAFV-.*|" // 840 Series, tested with SAMSUNG MZ7TD256HAFV-000L7/DXT06L6Q
-    "SAMSUNG MZMTD(128|256|512)HAGL-.*|" // PM841, tested with SAMSUNG MZMTD512HAGL-00000/DXT4200Q
-    "SAMSUNG MZ7TD512HAGM-.*|" // Another PM841, SAMSUNG MZ7TD512HAGM-000L1/DXT06L0Q
+    "SAMSUNG MZ[7M]TD(128|256|512)HA[GF][LMV]-.*|" // PM841, tested with SAMSUNG MZMTD512HAGL-00000/DXT4200Q,
+      // SAMSUNG MZ7TD512HAGM-000L1/DXT06L0Q, SAMSUNG MZMTD128HAFV-000L1/DXT43L0Q
     "SAMSUNG MZ7WD((120|240)H[AC]FV|480HAGM|960HAGP)-00003|" // SM843T Series, tested with
       // SAMSUNG MZ7WD120HAFV-00003/DXM85W3Q, SAMSUNG MZ7WD120HCFV-00003/DXM9203Q
-    "SAMSUNG MZ[7N]TE(128|256|512)HMHP-.*|" // PM851, tested with SAMSUNG MZ7TE256HMHP-000L7/EXT09L6Q,
-      // SAMSUNG MZNTE256HMHP-000H1/EXT22H0Q
+    "SAMSUNG MZ[7N]TE(128|256|512)HM(HP|JH)-.*|" // PM851, tested with SAMSUNG MZ7TE256HMHP-000L7/EXT09L6Q,
+      // SAMSUNG MZNTE256HMHP-000H1/EXT22H0Q, SAMSUNG MZNTE512HMJH-000L2/EXT26L0Q
     "SAMSUNG MZMPF(032|064)HCFV-.*|" // CM851 mSATA, tested with SAMSUNG MZMPF032HCFV-000H1/FXM42H2Q
     "SAMSUNG MZ7GE(240HMGR|(480|960)HMHP)-00003|" // SM853T Series, tested with
       // SAMSUNG MZ7GE240HMGR-00003/EXT0303Q
@@ -1865,8 +1868,8 @@ const drive_settings builtin_knowndrives[] = {
       // SAMSUNG MZ7KM960HMJP-00005/GXM5304Q, MZ7KM960HMJP0D3/GD53 (Dell)
     "SAMSUNG MZ7LH(240|480|960|1T9|3T8|7T6)H[AM](HQ|JR|LT|LA)-.*|" //PM883, tested with SAMSUNG MZ7LH960HAJR-00005
     "SAMSUNG MZ7KH(240|480|960|1T9|3T8)HA(HQ|JR|LS)-.*|" //SM883
-    "SAMSUNG MZN(LF|TY)(128|256)H[CD]HP-.*|" // CM871/871a, tested with SAMSUNG MZNLF128HCHP-000H1/FXT21H1Q,
-      // SAMSUNG MZNTY256HDHP-000/MAT21K0Q
+    "SAMSUNG MZ[7N](LF|TY)(128|192|256)H[CD](GS|HP)-.*|" // CM871/871a, tested with SAMSUNG MZNLF128HCHP-000H1/FXT21H1Q,
+      // SAMSUNG MZNTY256HDHP-000/MAT21K0Q, SAMSUNG MZ7LF192HCGS-000L1/FXT03L1Q
     "SAMSUNG MZ[7NY]LN(128|256|512|1T0)H[ACM](GR|HP|HQ|J[HPQ]|LR)-.*|" // PM871/871a/b, tested with
       // SAMSUNG MZ7LN128HCHP-00000/EMT0100Q, SAMSUNG MZ7LN256HAHQ-000H1/MVT03H6Q,
       // SAMSUNG MZNLN256HMHQ-000H1/MAV21H3Q, SAMSUNG MZYLN256HCHP-000L2/EMT63L0Q
@@ -2079,7 +2082,7 @@ const drive_settings builtin_knowndrives[] = {
     "LITEON LMH-(128|256|512)V2M-.*|" // tested with LITEON LMH-256V2M-11 MSATA 256GB/FM8110C
     "LITEON LCH-(128|256V|512)2S-.*|" // tested with LITEON LCH-256V2S-HP/2C02
     "MKNSSDRE(1TB|2TB|512GB|500GB|256GB|250GB)|" // tested with MKNSSDRE256GB/N1007C
-    "MKNSSDTR(240|500|250|120|480|240)GB(-LT)?|" // tested with MKNSSDTR500GB/O1126A
+    "MKNSSD(S2|TR)(120|2[45]0|480|500)GB(-LT)?|" // tested with MKNSSDS2500GB/T0818A0, MKNSSDTR500GB/O1126A
     "NFN025SA31T-.*|"// Neo Forza (?), from HP Laptop, tested with NFN025SA31T-6000000/S0628A0
     "OWC Envoy Pro|" // tested with OWC Envoy Pro/R0522A0 (0x1e91:0xa2a5)
     "Patriot P200 ((128|256|512)GB|[12]TB)|" // tested with Patriot P200 256GB/S1022A0
@@ -2110,6 +2113,7 @@ const drive_settings builtin_knowndrives[] = {
     "", "",
   //"-v 1,raw48,Raw_Read_Error_Rate "
   //"-v 2,raw48,Throughput_Performance "
+  //"-v 5,raw16(raw16),Reallocated_Sector_Ct "
   //"-v 9,raw24(raw8),Power_On_Hours "
   //"-v 12,raw48,Power_Cycle_Count "
     "-v 148,raw48,Total_SLC_Erase_Ct "
@@ -2282,7 +2286,8 @@ const drive_settings builtin_knowndrives[] = {
   //"-v 194,tempminmax,Temperature_Celsius"
   },
   { "SSSTC ER2 GD/CD Series SSDs", // Marvel DEAN 2.1
-    "SSSTC ER2-[CG]D(240|480|960|1920)", // tested with SSSTC ER2-GD480/E4N2302
+    "SSSTC ER2-[CG]D(240|480|960|1920)A?", // tested with SSSTC ER2-GD480/E4N2302l,
+      // SSSTC ER2-CD1920A/E5MN401
     "","",
   //"-v 5,raw16(raw16),Reallocated_Sector_Ct "
   //"-v 9,raw24(raw8),Power_On_Hours "
@@ -2326,6 +2331,22 @@ const drive_settings builtin_knowndrives[] = {
     "-v 7,raw48,Unknown_Attribute "
     "-v 8,raw48,Unknown_Attribute"
   },
+  { "Xmore Industrial SATA SSDs", // tested with M2CA032GXAIMS-003Z/XP01.1GB
+    "(CFAST|M2[AC]A|MSATA|SSD)[0-9]{3}[GT]XA[CEI][MT][MST]-[0-9]{3}[TZ]",
+    "", "",
+  //"-v 1,raw48,Raw_Read_Error_Rate "
+  //"-v 9,raw24(raw8),Power_On_Hours "
+  //"-v 12,raw48,Power_Cycle_Count "
+    "-v 168,raw48,SATA_Phy_Error_Count "
+    "-v 169,raw48,Bad_Block_Rate "
+    "-v 170,raw24/raw24:z54z10,Bad_Blk_Ct_Lat/Erl " // Later bad block/Early bad block
+    "-v 173,raw16(avg16),MaxAvgErase_Ct "
+    "-v 192,raw48,Unexpect_Power_Loss_Ct "
+  //"-v 194,tempminmax,Temperature_Celsius " // optional
+    "-v 218,raw48,SATA_CRC_Error_Count "
+    "-v 231,raw48,Percent_Lifetime_Remain "
+    "-v 241,raw48,Host_Writes_GiB"
+  },
   { "Marvell SSD SD88SA024BA0 (SUN branded)",
     "MARVELL SD88SA024BA0 SUN24G 0902M0054V",
     "", "", ""
@@ -3528,6 +3549,12 @@ const drive_settings builtin_knowndrives[] = {
     "", "",
     "-v 22,raw48,Helium_Level"
   },
+  { "Western Digital Ultrastar DC HC550", // tested with WDC  WUH721818ALE6L4/PCGNW110,
+      // WUH721818ALE6L4/PCGAW232
+    "(WDC  ?)?WUH72181[68]ALE6L[14]",
+    "", "",
+    "-v 22,raw48,Helium_Level"
+  },
   { "HGST MegaScale 4000", // tested with HGST HMS5C4040ALE640/MPAOA580
     "HGST HMS5C4040[AB]LE64[01]", // B = DC 4000.B
     "", "", ""
@@ -3632,7 +3659,7 @@ const drive_settings builtin_knowndrives[] = {
     "", "", ""
   },
   { "Toshiba 2.5\" HDD MQ01ABD...", // tested with TOSHIBA MQ01ABD100/AX001U,
-      // TOSHIBA MQ01ABD100V/AX001Q
+      // TOSHIBA MQ01ABD100/AX1R4C, TOSHIBA MQ01ABD100V/AX001Q
     "TOSHIBA MQ01ABD(025|032|050|064|075|100)V?",
     "", "", ""
   },
@@ -3675,12 +3702,13 @@ const drive_settings builtin_knowndrives[] = {
     "TOSHIBA MG03ACA[1234]00Y?",
     "", "", ""
   },
-  { "Toshiba 3.5\" MD04ACA... Enterprise HDD", // tested with TOSHIBA MD04ACA500/FP1A
-    "TOSHIBA MD04ACA[2345]00",
+  { "Toshiba MG04ACA... Enterprise HDD", // tested with TOSHIBA MD04ACA500/FP1A,
+      // TOSHIBA MG04ACA600A/FS2B, TOSHIBA MG04ACA400NY/FK5D (Dell)
+    "TOSHIBA MG04ACA[23456]00([AEN].?)?",
     "", "", ""
   },
-  { "Toshiba 3.5\" MG04ACA... Enterprise HDD", // tested with TOSHIBA MG04ACA600A/FS2B
-    "TOSHIBA MG04ACA[23456]00[AE].?",
+  { "Toshiba MG05ACA... Enterprise Capacity HDD", // tested with TOSHIBA MG05ACA800E/GX2A
+    "TOSHIBA MG05ACA800[AE]",
     "", "", ""
   },
   { "Toshiba MG06ACA... Enterprise Capacity HDD", // tested with TOSHIBA MG06ACA800E/4303,
@@ -3694,6 +3722,20 @@ const drive_settings builtin_knowndrives[] = {
     "-v 23,raw48,Helium_Condition_Lower "
     "-v 24,raw48,Helium_Condition_Upper"
   },
+  { "Toshiba MG08ACA... Enterprise Capacity HDD", // tested with TOSHIBA MG08ACA14TE/0102,
+      // TOSHIBA MG08ACA16TE/0102
+    "TOSHIBA MG08ACA1[46]T[AE]Y?",
+    "", "",
+    "-v 23,raw48,Helium_Condition_Lower "
+    "-v 24,raw48,Helium_Condition_Upper"
+  },
+  { "Toshiba MG09ACA... Enterprise Capacity HDD", // tested with TOSHIBA MG09ACA18TE/0102
+    "TOSHIBA MG09ACA1[68]T[AE]Y?",
+    "", "",
+    "-v 23,raw48,Helium_Condition_Lower "
+    "-v 24,raw48,Helium_Condition_Upper "
+    "-v 27,raw48,MAMR_Health_Monitor"
+  },
   { "Toshiba 3.5\" DT01ABA... Desktop HDD", // tested with TOSHIBA DT01ABA300/MZ6OABB0
     "TOSHIBA DT01ABA(100|150|200|300)",
     "", "", ""
@@ -3703,14 +3745,30 @@ const drive_settings builtin_knowndrives[] = {
     "TOSHIBA DT01ACA(025|032|050|075|100|150|200|300)",
     "", "", ""
   },
-  { "Toshiba X300", // tested with TOSHIBA HDWE160/FS2A
-    "TOSHIBA HDWE1[456]0",
+  { "Toshiba N300/MN NAS HDD", // tested with TOSHIBA HDWQ140/FJ1M, TOSHIBA HDWN160/FS1M,
+      // TOSHIBA HDWN180/GX2M, TOSHIBA HDWG480/0601 (8TB), TOSHIBA HDWG11A/0603 (10TB),
+      // TOSHIBA HDWG21C/0601 (12TB), TOSHIBA HDWG21E/0601 (14TB),
+      // TOSHIBA MN07ACA12T/0601, TOSHIBA MN08ACA14T/0601
+    "TOSHIBA HDW([GNQ]1[468]0|G(480|11A|21[CE]|31G))|" // 31G: 16TB
+    "TOSHIBA MN0(4ACA400|6ACA([68]00|10T)|7ACA1[24]T|8ACA1[46]T)",
+    "", "",
+    "-v 23,raw48,Helium_Condition_Lower " // ] >= 12TB
+    "-v 24,raw48,Helium_Condition_Upper"  // ]
+  },
+  { "Toshiba P300 (CMR)", // tested with TOSHIBA HDWD120/MX4OACF0
+    "TOSHIBA HDWD1(05|10|20|30)",
     "", "", ""
   },
-  { "Toshiba P300", // tested with TOSHIBA HDWD120/MX4OACF0
-    "TOSHIBA HDWD1(30|20|10|05)",
+  { "Toshiba P300 (SMR)", // tested with TOSHIBA HDWD240/KQ000A
+    "TOSHIBA HDWD2[246]0",
     "", "", ""
   },
+  { "Toshiba X300", // tested with TOSHIBA HDWE160/FS2A, TOSHIBA HDWF180/GX0B
+    "TOSHIBA HDW(E1[456]0|[FR]180|R(11A|21[CE]|31G))",  // 11A:10TB, 21C:12TB, 21E:14TB, 31G: 16TB
+    "", "",
+    "-v 23,raw48,Helium_Condition_Lower " // ] >= 12TB
+    "-v 24,raw48,Helium_Condition_Upper"  // ]
+  },
   { "Toshiba L200 (CMR)",
     "TOSHIBA HDW[JK]1(05|10)",
     "", "", ""
@@ -4056,16 +4114,23 @@ const drive_settings builtin_knowndrives[] = {
     "", "",
     "-v 188,raw16 -v 240,msec24hour32"
   },
-  { "Seagate BarraCuda 3.5", // tested with ST1000DM010-2EP102/Z9ACZM97,
-      // ST2000DM008-2FR102/0001, ST3000DM008-2DM166/CC26, ST4000DM005-2DP166/0001,
-      // ST4000DM006-2G5107/DN02, ST8000DM004-2CX188/0001, ST10000DM0004-1ZC101/DN01,
+  { "Seagate BarraCuda 3.5 (CMR)", // tested with ST1000DM010-2EP102/CC43,
+      // ST3000DM008-2DM166/CC26, ST4000DM006-2G5107/DN02, ST10000DM0004-1ZC101/DN01,
       // ST12000DM0007-2GR116/DN01
-    "ST(500DM009|1000DM010|2000DM00[5-9]|3000DM00[789]|4000DM00[456]|6000DM00[34]|"
-       "8000DM00[45]|10000DM0004|12000DM0007)-.*",
+    "ST(500DM009|1000DM010|2000DM00[67]|3000DM00[89]|4000DM006|6000DM004|"
+       "8000DM005|10000DM0004|12000DM0007)-.*",
     "", "",
     "-v 200,raw48,Pressure_Limit "
     "-v 188,raw16 -v 240,msec24hour32"
   },
+  { "Seagate BarraCuda 3.5 (SMR)", // tested with ST2000DM008-2FR102/0001,
+      // ST4000DM004-2CV104/0001 (TRIM: no), ST4000DM005-2DP166/0001, ST8000DM004-2CX188/0001
+    "ST(2000DM00[589]|3000DM007|4000DM00[45]|6000DM003|8000DM004)-.*",
+    "", "",
+    "-v 9,msec24hour32 " // ST4000DM004-2CV104/0001
+    "-v 200,raw48,Pressure_Limit "
+    "-v 188,raw16 -v 240,msec24hour32"
+  },
   { "Seagate Desktop HDD.15", // tested with ST4000DM000-1CD168/CC43, ST5000DM000-1FK178/CC44,
       // ST6000DM001-1XY17Z/CC48
     "ST[4568]000DM00[012]-.*",
@@ -4206,6 +4271,17 @@ const drive_settings builtin_knowndrives[] = {
     "", "",
     "-v 9,msec24hour32 -v 240,msec24hour32"
   },
+  // ST1000NM000A, ST1000NM002A, ST2000NM000A, ST2000NM001A, ST2000NM002A,
+  // ST3000NM000A, ST3000NM004A, ST4000NM000A, ST4000NM001A, ST4000NM002A,
+  // ST4000NM006A, ST4000NM010A, ST4000NM012A, ST4000NM013A, ST6000NM002A,
+  // ST6000NM021A, ST6000NM022A, ST6000NM025A, ST6000NM026A, ST8000NM000A,
+  // ST8000NM002A, ST8000NM004A, ST8000NM008A, ST8000NM009A, ST8000NM016A
+  { "Seagate Exos 7E8", // tested with ST6000NM021A-2R7101/SN02, ST8000NM000A-2KE101/SN02
+    "ST[123468]000NM0(0[01234689]|1[0236]|2[1256])A-.*",
+    "", "",
+    "-v 18,raw48,Head_Health "
+    "-v 240,msec24hour32"
+  },
   { "Seagate Exos X12", // tested with ST12000NM0007-2A1101/SN02
     "ST12000NM00[01]7-.*", // *17 = SED
     "", "",
@@ -4244,12 +4320,14 @@ const drive_settings builtin_knowndrives[] = {
     "", "", ""
   },
   { "Seagate IronWolf", // tested with ST3000VN007-2E4166/SC60, ST4000VN008-2DR166/SC60,
-      // ST6000VN0033-2EE110/SC60, ST6000VN0041-2EL11C/SC61, ST8000VN0022-2EL112/SC61,
-      // ST10000VN0004-1ZD101/SC60, ST12000VN0007-2GS116/SC60, ST12000VN0008-2JH101/SC60
+      // ST6000VN001-2BB186/SC60, ST6000VN0033-2EE110/SC60, ST6000VN0041-2EL11C/SC61,
+      // ST8000VN0022-2EL112/SC61, ST10000VN0004-1ZD101/SC60,
+      // ST12000VN0007-2GS116/SC60, ST12000VN0008-2JH101/SC60
     "ST(1|2|3|4|6|8|10|12)000VN00(0?[2478]|1|22|33|41)-.*",
     "", "",
     "-v 18,raw48,Head_Health "
-    "-v 200,raw48,Pressure_Limit"
+    "-v 200,raw48,Pressure_Limit "
+    "-v 240,msec24hour32"
   },
   { "Seagate IronWolf Pro", // tested with ST4000NE0025-2EW107/EN02,
       // ST8000NE0004-1ZF11G/EN01, ST8000NE0021-2EN112/EN02, ST16000NE000-2RW103/EN02
@@ -4578,8 +4656,8 @@ const drive_settings builtin_knowndrives[] = {
     "(APPLE HDD )?WDC WD((25|32|50)00AAKX|5000AZ(LX|RZ)|7500A(AL|ZE)X|10E(AL|ZE)X|[1-6]0EZRZ)-.*",
     "", "", ""
   },
-  { "Western Digital Blue (SMR)", // ticket #1313
-    "WDC WD(20|60)EZAZ-.*",
+  { "Western Digital Blue (SMR)", // tested with WDC WD40EZAZ-00SF3B0/80.00A80 (TRIM: zeroed)
+    "WDC WD(20|40|60)EZAZ-.*",
     "", "", ""
   },
   { "Western Digital RE Serial ATA",
@@ -5261,8 +5339,8 @@ const drive_settings builtin_knowndrives[] = {
     "-d sat"
   },
   { "USB: LaCie; ", // 0x1070: ASMedia 1053 ?
-    "0x059f:0x10(6f|7[05])",
-    "", // 6f/70=0x0001, 75=0x0000
+    "0x059f:0x10(6f|7[05]|b8)", // 0x0x10b8: d2 PROFESSIONAL
+    "", // 6f/70/b8=0x0001, 75=0x0000
     "",
     "-d sat"
   },
@@ -5511,6 +5589,18 @@ const drive_settings builtin_knowndrives[] = {
     "",
     "-d sntrealtek"
   },
+  { "USB: ; Realtek RTL9211", // USB->PCIe (NVMe) or SATA
+    "0x(0bda|2eb9):0x9211", // 0x0bda: guessed, 0x2eb9: Sabrent EC-WPTF
+    ".*", // fall through to next entry and report ambiguous result
+    "",
+    "-d sntrealtek" // NVMe or ...
+  },
+  { "USB: ; Realtek RTL9211",
+    "0x(0bda|2eb9):0x9211",
+    "",
+    "",
+    "" // ... SATA (unsupported)
+  },
   // Addonics
   { "USB: Addonics HDMU3; ", // (ticket #609)
     "0x0bf6:0x1001",
@@ -5637,9 +5727,10 @@ const drive_settings builtin_knowndrives[] = {
   },
   // ADATA
   { "USB: ADATA; ",
-    "0x125f:0xa(11|13|15|31|35|37|75|83)a", // 0xa11a: Classic CH11 1TB, 0xa13a: NH13 1TB,
-    "", // 0xa15a: HD710 1TB, 0xa31a: HV620 2TB (0x0100), 0xa35a: HD650 2TB (0x6503),
-    "", // 0xa37a: Silverstone MS10 M.2 (0x3103), 0xa75a: HD710P 4TB, 0xa83a: HD330 (0x0100)
+    "0x125f:0xa(11|13|15|21|31|35|37|75|83)a", // 0xa11a: Classic CH11 1TB, 0xa13a: NH13 1TB,
+    "", // 0xa15a: HD710 1TB, 0xa21a: HV610 (0x4504), 0xa31a: HV620 2TB (0x0100),
+    "", // 0xa35a: HD650 2TB (0x6503), 0xa37a: Silverstone MS10 M.2 (0x3103), 0xa75a: HD710P 4TB,
+        // 0xa83a: HD330 (0x0100)
     "-d sat"
   },
   { "USB: ADATA; Cypress",
@@ -5755,7 +5846,7 @@ const drive_settings builtin_knowndrives[] = {
     "-d sat"
   },
   { "USB: ; JMicron JMS576", // USB3.1->SATA
-    "0x152d:0x1576",
+    "0x152d:0x[01]576",
     "", // 0x0204, ICY BOX IB-223U3a-B
     "",
     "-d sat"
@@ -5858,6 +5949,12 @@ const drive_settings builtin_knowndrives[] = {
     "-d sat"
   },
   // ASMedia
+  { "USB: ; ASMedia ASM2362", // USB->PCIe (NVMe)
+    "0x174c:0x2362",
+    "",
+    "",
+    "-d sntasmedia"
+  },
   { "USB: ; ASMedia",
     "0x174c:0x....",
     "",
@@ -6019,6 +6116,7 @@ const drive_settings builtin_knowndrives[] = {
     "",
     "-d sat"
   },
+  // 0x2eb9 (?): See Realtek (0x0bda) above
   // AKiTiO (?)
   { "USB: AkiTio NT2 U3.1C; ",
     "0x2ce5:0x0014",
