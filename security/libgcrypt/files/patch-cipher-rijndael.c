--- cipher/rijndael.c.orig	2011-02-22 15:57:59.000000000 +0100
+++ cipher/rijndael.c	2011-07-26 08:38:07.000000000 +0200
@@ -844,13 +844,13 @@ do_aesni_cfb (const RIJNDAEL_context *ct
                 "movdqa 0x90(%%esi), %%xmm1\n\t"
                 aesenc_xmm1_xmm0
                 "movdqa 0xa0(%%esi), %%xmm1\n\t"
-                "cmp $10, %[rounds]\n\t"
+                "cmpl $10, %[rounds]\n\t"
                 "jz .Lenclast%=\n\t"
                 aesenc_xmm1_xmm0
                 "movdqa 0xb0(%%esi), %%xmm1\n\t"
                 aesenc_xmm1_xmm0
                 "movdqa 0xc0(%%esi), %%xmm1\n\t"
-                "cmp $12, %[rounds]\n\t"
+                "cmpl $12, %[rounds]\n\t"
                 "jz .Lenclast%=\n\t"
                 aesenc_xmm1_xmm0
                 "movdqa 0xd0(%%esi), %%xmm1\n\t"
@@ -862,7 +862,7 @@ do_aesni_cfb (const RIJNDAEL_context *ct
                 "movdqu %[src], %%xmm1\n\t"      /* Save input.  */
                 "pxor %%xmm1, %%xmm0\n\t"        /* xmm0 = input ^ IV  */
 
-                "cmp $1, %[decrypt]\n\t"
+                "cmpl $1, %[decrypt]\n\t"
                 "jz .Ldecrypt_%=\n\t"
                 "movdqa %%xmm0, %[iv]\n\t"       /* [encrypt] Store IV.  */
                 "jmp .Lleave_%=\n"
@@ -923,13 +923,13 @@ do_aesni_ctr (const RIJNDAEL_context *ct
                 "movdqa 0x90(%%esi), %%xmm1\n\t"
                 aesenc_xmm1_xmm0
                 "movdqa 0xa0(%%esi), %%xmm1\n\t"
-                "cmp $10, %[rounds]\n\t"
+                "cmpl $10, %[rounds]\n\t"
                 "jz .Lenclast%=\n\t"
                 aesenc_xmm1_xmm0
                 "movdqa 0xb0(%%esi), %%xmm1\n\t"
                 aesenc_xmm1_xmm0
                 "movdqa 0xc0(%%esi), %%xmm1\n\t"
-                "cmp $12, %[rounds]\n\t"
+                "cmpl $12, %[rounds]\n\t"
                 "jz .Lenclast%=\n\t"
                 aesenc_xmm1_xmm0
                 "movdqa 0xd0(%%esi), %%xmm1\n\t"
@@ -1050,7 +1050,7 @@ do_aesni_ctr_4 (const RIJNDAEL_context *
                 aesenc_xmm1_xmm3
                 aesenc_xmm1_xmm4
                 "movdqa 0xa0(%%esi), %%xmm1\n\t"
-                "cmp $10, %[rounds]\n\t"
+                "cmpl $10, %[rounds]\n\t"
                 "jz .Lenclast%=\n\t"
                 aesenc_xmm1_xmm0
                 aesenc_xmm1_xmm2
@@ -1062,7 +1062,7 @@ do_aesni_ctr_4 (const RIJNDAEL_context *
                 aesenc_xmm1_xmm3
                 aesenc_xmm1_xmm4
                 "movdqa 0xc0(%%esi), %%xmm1\n\t"
-                "cmp $12, %[rounds]\n\t"
+                "cmpl $12, %[rounds]\n\t"
                 "jz .Lenclast%=\n\t"
                 aesenc_xmm1_xmm0
                 aesenc_xmm1_xmm2
