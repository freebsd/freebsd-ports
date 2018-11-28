--- vendor/golang.org/x/crypto/blake2b/blake2b_amd64.s.orig	2018-10-12 12:43:05 UTC
+++ vendor/golang.org/x/crypto/blake2b/blake2b_amd64.s
@@ -279,12 +279,3 @@ noinc:
 
 	MOVQ BP, SP
 	RET
-
-// func supportsSSE4() bool
-TEXT ·supportsSSE4(SB), 4, $0-1
-	MOVL $1, AX
-	CPUID
-	SHRL $19, CX  // Bit 19 indicates SSE4 support
-	ANDL $1, CX  // CX != 0 if support SSE4
-	MOVB CX, ret+0(FP)
-	RET
