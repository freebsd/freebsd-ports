Obtained from:	https://git.lysator.liu.se/nettle/nettle/-/commit/d4c7597e4236f746434c9a1a24f6191f7ff870cd

--- powerpc64/p7/chacha-4core.asm.orig	2022-06-02 17:57:16 UTC
+++ powerpc64/p7/chacha-4core.asm
@@ -53,59 +53,66 @@ define(`T1', `v21')
 define(`T2', `v22')
 define(`T3', `v23')
 
+C A workaround for expanding multiple digits of argument references to QR macro which is incompatible with POSIX
+C See https://www.gnu.org/software/m4/manual/html_node/Arguments.html
+define(`P1',
+`ifelse($1, 0, v0, $1, 1, v4, $1, 2, v8, $1, 3, v12, $1, 4, v1, $1, 5, v5, $1, 6, v9, $1, 7, v13, $1, 8, v2, $1, 9, v6, $1, 10, v10, $1, 11, v14, $1, 12, v3, $1, 13, v7, $1, 14, v11, $1, 15, v15)')
+define(`P2',
+`ifelse($1, 0, v0, $1, 1, v5, $1, 2, v10, $1, 3, v15, $1, 4, v1, $1, 5, v6, $1, 6, v11, $1, 7, v12, $1, 8, v2, $1, 9, v7, $1, 10, v8, $1, 11, v13, $1, 12, v3, $1, 13, v4, $1, 14, v9, $1, 15, v14)')
+
 C Main loop for round
 define(`QR',`
-	vadduwm $1, $1, $2
-	vadduwm $5, $5, $6
-	vadduwm $9, $9, $10
-	vadduwm $13, $13, $14
-	vxor	$4, $4, $1
-	vxor	$8, $8, $5
-	vxor	$12, $12, $9
-	vxor	$16, $16, $13
-	vrlw	$4, $4, ROT16
-	vrlw	$8, $8, ROT16
-	vrlw	$12, $12, ROT16
-	vrlw	$16, $16, ROT16
+	vadduwm $1(0), $1(0), $1(1)
+	vadduwm $1(4), $1(4), $1(5)
+	vadduwm $1(8), $1(8), $1(9)
+	vadduwm $1(12), $1(12), $1(13)
+	vxor	$1(3), $1(3), $1(0)
+	vxor	$1(7), $1(7), $1(4)
+	vxor	$1(11), $1(11), $1(8)
+	vxor	$1(15), $1(15), $1(12)
+	vrlw	$1(3), $1(3), ROT16
+	vrlw	$1(7), $1(7), ROT16
+	vrlw	$1(11), $1(11), ROT16
+	vrlw	$1(15), $1(15), ROT16
 
-	vadduwm $3, $3, $4
-	vadduwm $7, $7, $8
-	vadduwm $11, $11, $12
-	vadduwm $15, $15, $16
-	vxor	$2, $2, $3
-	vxor	$6, $6, $7
-	vxor	$10, $10, $11
-	vxor	$14, $14, $15
-	vrlw	$2, $2, ROT12
-	vrlw	$6, $6, ROT12
-	vrlw	$10, $10, ROT12
-	vrlw	$14, $14, ROT12
+	vadduwm $1(2), $1(2), $1(3)
+	vadduwm $1(6), $1(6), $1(7)
+	vadduwm $1(10), $1(10), $1(11)
+	vadduwm $1(14), $1(14), $1(15)
+	vxor	$1(1), $1(1), $1(2)
+	vxor	$1(5), $1(5), $1(6)
+	vxor	$1(9), $1(9), $1(10)
+	vxor	$1(13), $1(13), $1(14)
+	vrlw	$1(1), $1(1), ROT12
+	vrlw	$1(5), $1(5), ROT12
+	vrlw	$1(9), $1(9), ROT12
+	vrlw	$1(13), $1(13), ROT12
 
-	vadduwm $1, $1, $2
-	vadduwm $5, $5, $6
-	vadduwm $9, $9, $10
-	vadduwm $13, $13, $14
-	vxor	$4, $4, $1
-	vxor	$8, $8, $5
-	vxor	$12, $12, $9
-	vxor	$16, $16, $13
-	vrlw	$4, $4, ROT8
-	vrlw	$8, $8, ROT8
-	vrlw	$12, $12, ROT8
-	vrlw	$16, $16, ROT8
+	vadduwm $1(0), $1(0), $1(1)
+	vadduwm $1(4), $1(4), $1(5)
+	vadduwm $1(8), $1(8), $1(9)
+	vadduwm $1(12), $1(12), $1(13)
+	vxor	$1(3), $1(3), $1(0)
+	vxor	$1(7), $1(7), $1(4)
+	vxor	$1(11), $1(11), $1(8)
+	vxor	$1(15), $1(15), $1(12)
+	vrlw	$1(3), $1(3), ROT8
+	vrlw	$1(7), $1(7), ROT8
+	vrlw	$1(11), $1(11), ROT8
+	vrlw	$1(15), $1(15), ROT8
 
-	vadduwm $3, $3, $4
-	vadduwm $7, $7, $8
-	vadduwm $11, $11, $12
-	vadduwm $15, $15, $16
-	vxor	$2, $2, $3
-	vxor	$6, $6, $7
-	vxor	$10, $10, $11
-	vxor	$14, $14, $15
-	vrlw	$2, $2, ROT7
-	vrlw	$6, $6, ROT7
-	vrlw	$10, $10, ROT7
-	vrlw	$14, $14, ROT7
+	vadduwm $1(2), $1(2), $1(3)
+	vadduwm $1(6), $1(6), $1(7)
+	vadduwm $1(10), $1(10), $1(11)
+	vadduwm $1(14), $1(14), $1(15)
+	vxor	$1(1), $1(1), $1(2)
+	vxor	$1(5), $1(5), $1(6)
+	vxor	$1(9), $1(9), $1(10)
+	vxor	$1(13), $1(13), $1(14)
+	vrlw	$1(1), $1(1), ROT7
+	vrlw	$1(5), $1(5), ROT7
+	vrlw	$1(9), $1(9), ROT7
+	vrlw	$1(13), $1(13), ROT7
 ')
 
 define(`TRANSPOSE',`
@@ -185,8 +192,8 @@ C Load state and splat
 	srdi	ROUNDS, ROUNDS, 1
 	mtctr	ROUNDS
 .Loop:
-	QR(v0, v4,  v8, v12, v1, v5,  v9, v13, v2, v6, v10, v14, v3, v7, v11, v15)
-	QR(v0, v5, v10, v15, v1, v6, v11, v12, v2, v7,  v8, v13, v3, v4,  v9, v14)
+	QR(`P1')
+	QR(`P2')
 	bdnz	.Loop
 
 	C Add in saved original words, including counters, before
