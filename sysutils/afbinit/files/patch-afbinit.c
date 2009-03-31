/*
 * Creator, Creator3D and Elite3D framebuffer driver.
 *
 * Copyright (C) 2000 Jakub Jelinek (jakub@redhat.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * JAKUB JELINEK BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
/* XFree86: xc/programs/Xserver/hw/xfree86/drivers/sunffb/ffb_driver.c,v 1.11 2002/12/06 02:44:04 tsi Exp */

--- afbinit.c.orig	Fri Nov 30 03:04:21 2001
+++ afbinit.c	Mon Sep 15 17:33:19 2003
@@ -186,7 +186,7 @@
 
 static void usage(char *me)
 {
-	printf("Usage:	%s /dev/fb[0123] [ucode_file]\n", me);
+	printf("Usage:	%s /dev/fb[0-7] [ucode_file]\n", me);
 	exit(1);
 }
 
@@ -195,13 +195,14 @@
 	struct afb_ucode_header {
 		char ident[8];
 		unsigned int ucode_words;
-		unsigned int __unused[2];
+		unsigned int unused[2];
 	} ucheader;
 	unsigned int *ucode;
 	int afb_fd, ucode_fd, ucode_version;
 	void *uregs, *kregs;
 	char *afb_fname;
 	char *ucode_fname = UCODE_FILE;
+	unsigned int fem;
 
 	if(argc != 2 && argc != 3)
 		usage(argp[0]);
@@ -224,7 +225,7 @@
 		perror("Read UCODE header");
 		exit(1);
 	}
-	ucode = (unsigned int *)malloc(ucheader.ucode_words << 2);
+	ucode = (unsigned int *)(uintptr_t)malloc(ucheader.ucode_words << 2);
 	if(ucode == NULL) {
 		fprintf(stderr, "Cannot malloc %d bytes for UCODE.\n",
 			ucheader.ucode_words << 2);
@@ -256,15 +257,27 @@
 		exit(1);
 	}
 
-	/* Say what UCODE version we are loading. */
+	fem = *AFB_UREG_FEM(uregs) & 0x7f;
+	if (fem == 0x07 || fem == 0x3f) {
+		fprintf(stderr, "%s: Elite3D/M%s microcode already loaded.\n",
+			afb_fname, fem == 0x07 ? "3" : "6");
+		exit(1);
+	}
+	if (fem != 0x01) {
+		fprintf(stderr, "%s: Not an AFB board.\n", afb_fname);
+		exit(1);
+	}
+
+	afb_ucode_upload((char *)ucode, ucheader.ucode_words / 16, uregs,
+		kregs);
 	ucode_version = *(ucode + (0x404 / sizeof(unsigned int)));
-	printf("Revision-%d.%d.%d ",
+	fem = *AFB_UREG_FEM(uregs) & 0x7f;
+	printf("%s: Elite3D/M%s microcode revision %d.%d.%d loaded.\n",
+		afb_fname, fem == 0x07 ? "3" : "6",
 	       (ucode_version >> 16) & 0xff,
 	       (ucode_version >>  8) & 0xff,
 	       (ucode_version >>  0) & 0xff);
 
-	afb_ucode_upload((char *)ucode, ucheader.ucode_words / 16, uregs, kregs);
-
 	munmap(kregs, 0x2000);
 	munmap(uregs, 0x2000);
 
