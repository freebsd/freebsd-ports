--- ./sha.cpp.orig	2009-03-15 02:48:00.000000000 -0700
+++ ./sha.cpp	2010-01-29 18:49:49.247445242 -0800
@@ -273,14 +273,15 @@
 #endif
 	AS2(	mov		STATE_SAVE, WORD_REG(cx))
 	AS2(	mov		DATA_SAVE, WORD_REG(dx))
-	AS2(	add		WORD_REG(di), WORD_REG(dx))
-	AS2(	mov		DATA_END, WORD_REG(di))
+	AS2(	lea		WORD_REG(ax), [WORD_REG(di) + WORD_REG(dx)])
+	AS2(	mov		DATA_END, WORD_REG(ax))
 	AS2(	mov		K_END, WORD_REG(si))
 
 #if CRYPTOPP_BOOL_SSE2_ASM_AVAILABLE
 #if CRYPTOPP_BOOL_X86
 	AS2(	test	edi, 1)
 	ASJ(	jnz,	2, f)
+	AS1(	dec		DWORD PTR K_END)
 #endif
 	AS2(	movdqa	xmm0, XMMWORD_PTR [WORD_REG(cx)+0*16])
 	AS2(	movdqa	xmm1, XMMWORD_PTR [WORD_REG(cx)+1*16])
@@ -355,7 +356,7 @@
 	ROUND(14, 1, eax, ecx, edi, edx)
 	ROUND(15, 1, ecx, eax, edx, edi)
 	AS2(	cmp		WORD_REG(si), K_END)
-	ASJ(	jne,	1, b)
+	ASJ(	jl,		1, b)
 
 	AS2(	mov		WORD_REG(dx), DATA_SAVE)
 	AS2(	add		WORD_REG(dx), 64)
@@ -364,8 +365,8 @@
 
 #if CRYPTOPP_BOOL_SSE2_ASM_AVAILABLE
 #if CRYPTOPP_BOOL_X86
-	AS2(	test	DWORD PTR DATA_END, 1)
-	ASJ(	jnz,	4, f)
+	AS2(	test	DWORD PTR K_END, 1)
+	ASJ(	jz,		4, f)
 #endif
 	AS2(	movdqa	xmm1, XMMWORD_PTR [AS_REG_7+1*16])
 	AS2(	movdqa	xmm0, XMMWORD_PTR [AS_REG_7+0*16])
