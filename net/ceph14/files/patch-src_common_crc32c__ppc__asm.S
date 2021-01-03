--- src/common/crc32c_ppc_asm.S.orig	2021-01-02 03:36:51.991947000 +0100
+++ src/common/crc32c_ppc_asm.S	2021-01-02 03:37:48.304305000 +0100
@@ -17,16 +17,25 @@
  * http://en.wikipedia.org/wiki/Barrett_reduction
  *
  * Copyright (C) 2015 Anton Blanchard <anton@au.ibm.com>, IBM
- * Copyright (C) 2017 International Business Machines Corp.
- * All rights reserved.
  *
  * This program is free software; you can redistribute it and/or
- * modify it under the terms of the GNU General Public License
- * as published by the Free Software Foundation; either version
- * 2 of the License, or (at your option) any later version.
+ * modify it under the terms of either:
+ *
+ *  a) the GNU General Public License as published by the Free Software
+ *     Foundation; either version 2 of the License, or (at your option)
+ *     any later version, or
+ *  b) the Apache License, Version 2.0
  */
+
+#if defined (__clang__)
+#ifndef __ALTIVEC__
+#define __ALTIVEC__
+#endif
+#include "ppc-asm.h"
+#else
 #include <ppc-asm.h>
-#include "common/ppc-opcode.h"
+#endif
+#include "ppc-opcode.h"
 
 #undef toc
 
@@ -45,8 +54,11 @@
 	/* byte reverse permute constant */
 	.octa 0x0F0E0D0C0B0A09080706050403020100
 
-#define __ASSEMBLY__
-#include "crc32c_ppc_constants.h"
+#ifdef CRC32_CONSTANTS_HEADER
+#include CRC32_CONSTANTS_HEADER
+#else
+#include "crc32c_ppc_constants.h"
+#endif
 
 	.text
 
@@ -80,8 +92,12 @@
 #define VPERM(A, B, C, D)
 #endif
 
+#ifndef CRC32_FUNCTION_ASM
+#define CRC32_FUNCTION_ASM __crc32_vpmsum
+#endif
+
 /* unsigned int __crc32_vpmsum(unsigned int crc, void *p, unsigned long len) */
-FUNC_START(__crc32_vpmsum)
+FUNC_START(CRC32_FUNCTION_ASM)
 	std	r31,-8(r1)
 	std	r30,-16(r1)
 	std	r29,-24(r1)
@@ -768,4 +784,4 @@
 	mr	r3,r10
 	b	.Lout
 
-FUNC_END(__crc32_vpmsum)
+FUNC_END(CRC32_FUNCTION_ASM)
