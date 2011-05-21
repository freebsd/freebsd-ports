diff -u dmidecode.c dmidecode.c
--- dmidecode.c	2011/01/25 16:19:42	1.167
+++ dmidecode.c	2011/04/20 14:37:03	1.168
@@ -707,6 +707,8 @@
 		{ 0x3A, "Athlon II Dual-Core M" },
 		{ 0x3B, "Opteron 6100" },
 		{ 0x3C, "Opteron 4100" },
+		{ 0x3D, "Opteron 6200" },
+		{ 0x3E, "Opteron 4200" },
 
 		{ 0x40, "MIPS" },
 		{ 0x41, "MIPS R4000" },
@@ -714,6 +716,10 @@
 		{ 0x43, "MIPS R4400" },
 		{ 0x44, "MIPS R4600" },
 		{ 0x45, "MIPS R10000" },
+		{ 0x46, "C-Series" },
+		{ 0x47, "E-Series" },
+		{ 0x48, "S-Series" },
+		{ 0x49, "G-Series" },
 
 		{ 0x50, "SPARC" },
 		{ 0x51, "SuperSPARC" },
@@ -997,7 +1003,8 @@
 		sig = 1;
 	else if ((type >= 0x18 && type <= 0x1D) /* AMD */
 	      || type == 0x1F /* AMD */
-	      || (type >= 0x38 && type <= 0x3C) /* AMD */
+	      || (type >= 0x38 && type <= 0x3E) /* AMD */
+	      || (type >= 0x46 && type <= 0x49) /* AMD */
 	      || (type >= 0x83 && type <= 0x8F) /* AMD */
 	      || (type >= 0xB6 && type <= 0xB7) /* AMD */
 	      || (type >= 0xE6 && type <= 0xEF)) /* AMD */
@@ -1143,10 +1150,20 @@
 		"Socket LGA1156",
 		"Socket LGA1567",
 		"Socket PGA988A",
-		"Socket BGA1288" /* 0x20 */
+		"Socket BGA1288",
+		"Socket rPGA988B",
+		"Socket BGA1023",
+		"Socket BGA1024",
+		"Socket BGA1155",
+		"Socket LGA1356",
+		"Socket LGA2011",
+		"Socket FS1",
+		"Socket FS2",
+		"Socket FM1",
+		"Socket FM2" /* 0x2A */
 	};
 
-	if (code >= 0x01 && code <= 0x20)
+	if (code >= 0x01 && code <= 0x2A)
 		return upgrade[code - 0x01];
 	return out_of_spec;
 }
@@ -1493,10 +1510,11 @@
 		"24-way Set-associative",
 		"32-way Set-associative",
 		"48-way Set-associative",
-		"64-way Set-associative" /* 0x0D */
+		"64-way Set-associative",
+		"20-way Set-associative" /* 0x0E */
 	};
 
-	if (code >= 0x01 && code <= 0x0D)
+	if (code >= 0x01 && code <= 0x0E)
 		return type[code - 0x01];
 	return out_of_spec;
 }
@@ -1660,12 +1678,18 @@
 		"PCI Express 2 x2",
 		"PCI Express 2 x4",
 		"PCI Express 2 x8",
-		"PCI Express 2 x16", /* 0xB0 */
+		"PCI Express 2 x16",
+		"PCI Express 3",
+		"PCI Express 3 x1",
+		"PCI Express 3 x2",
+		"PCI Express 3 x4",
+		"PCI Express 3 x8",
+		"PCI Express 3 x16" /* 0xB6 */
 	};
 
 	if (code >= 0x01 && code <= 0x13)
 		return type[code - 0x01];
-	if (code >= 0xA0 && code <= 0xB0)
+	if (code >= 0xA0 && code <= 0xB6)
 		return type_0xA0[code - 0xA0];
 	return out_of_spec;
 }
@@ -2100,7 +2124,7 @@
 
 	if (code >= 0x01 && code <= 0x0A)
 		return location[code - 0x01];
-	if (code >= 0xA0 && code <= 0xA4)
+	if (code >= 0xA0 && code <= 0xA3)
 		return location_0xA0[code - 0xA0];
 	return out_of_spec;
 }
