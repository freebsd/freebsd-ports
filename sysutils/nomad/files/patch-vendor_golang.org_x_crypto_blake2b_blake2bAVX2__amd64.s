--- vendor/golang.org/x/crypto/blake2b/blake2bAVX2_amd64.s.orig	2018-10-12 12:41:53 UTC
+++ vendor/golang.org/x/crypto/blake2b/blake2bAVX2_amd64.s
@@ -748,15 +748,3 @@ noinc:
 
 	MOVQ BP, SP
 	RET
-
-// func supportsAVX2() bool
-TEXT ·supportsAVX2(SB), 4, $0-1
-	MOVQ runtime·support_avx2(SB), AX
-	MOVB AX, ret+0(FP)
-	RET
-
-// func supportsAVX() bool
-TEXT ·supportsAVX(SB), 4, $0-1
-	MOVQ runtime·support_avx(SB), AX
-	MOVB AX, ret+0(FP)
-	RET
