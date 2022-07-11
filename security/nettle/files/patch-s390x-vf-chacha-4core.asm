Obtained from:	https://git.lysator.liu.se/nettle/nettle/-/commit/d4c7597e4236f746434c9a1a24f6191f7ff870cd

--- s390x/vf/chacha-4core.asm.orig	2022-06-02 17:57:16 UTC
+++ s390x/vf/chacha-4core.asm
@@ -48,59 +48,66 @@ define(`T3', `%v28')
 define(`T2', `%v27')
 define(`T3', `%v28')
 
+C A workaround for expanding multiple digits of argument references to QR macro which is incompatible with POSIX
+C See https://www.gnu.org/software/m4/manual/html_node/Arguments.html
+define(`P1',
+`ifelse($1, 0, v0, $1, 1, v1, $1, 2, v2, $1, 3, v3, $1, 4, v4, $1, 5, v5, $1, 6, v6, $1, 7, v7, $1, 8, v8, $1, 9, v9, $1, 10, v10, $1, 11, v11, $1, 12, v12, $1, 13, v13, $1, 14, v14, $1, 15, v15)')
+define(`P2',
+`ifelse($1, 0, v0, $1, 1, v5, $1, 2, v10, $1, 3, v15, $1, 4, v4, $1, 5, v9, $1, 6, v14, $1, 7, v3, $1, 8, v8, $1, 9, v13, $1, 10, v2, $1, 11, v7, $1, 12, v12, $1, 13, v1, $1, 14, v6, $1, 15, v11)')
+
 C Main loop for round
 define(`QR',`
-	vaf		$1, $1, $2
-	vaf		$5, $5, $6
-	vaf		$9, $9, $10
-	vaf		$13, $13, $14
-	vx		$4, $4, $1
-	vx		$8, $8, $5
-	vx		$12, $12, $9
-	vx		$16, $16, $13
-	verllf	$4, $4, 16
-	verllf	$8, $8, 16
-	verllf	$12, $12, 16
-	verllf	$16, $16, 16
+	vaf		$1(0), $1(0), $1(1)
+	vaf		$1(4), $1(4), $1(5)
+	vaf		$1(8), $1(8), $1(9)
+	vaf		$1(12), $1(12), $1(13)
+	vx		$1(3), $1(3), $1(0)
+	vx		$1(7), $1(7), $1(4)
+	vx		$1(11), $1(11), $1(8)
+	vx		$1(15), $1(15), $1(12)
+	verllf	$1(3), $1(3), 16
+	verllf	$1(7), $1(7), 16
+	verllf	$1(11), $1(11), 16
+	verllf	$1(15), $1(15), 16
 
-	vaf		$3, $3, $4
-	vaf		$7, $7, $8
-	vaf		$11, $11, $12
-	vaf		$15, $15, $16
-	vx		$2, $2, $3
-	vx		$6, $6, $7
-	vx		$10, $10, $11
-	vx		$14, $14, $15
-	verllf	$2, $2, 12
-	verllf	$6, $6, 12
-	verllf	$10, $10, 12
-	verllf	$14, $14, 12
+	vaf		$1(2), $1(2), $1(3)
+	vaf		$1(6), $1(6), $1(7)
+	vaf		$1(10), $1(10), $1(11)
+	vaf		$1(14), $1(14), $1(15)
+	vx		$1(1), $1(1), $1(2)
+	vx		$1(5), $1(5), $1(6)
+	vx		$1(9), $1(9), $1(10)
+	vx		$1(13), $1(13), $1(14)
+	verllf	$1(1), $1(1), 12
+	verllf	$1(5), $1(5), 12
+	verllf	$1(9), $1(9), 12
+	verllf	$1(13), $1(13), 12
 
-	vaf		$1, $1, $2
-	vaf		$5, $5, $6
-	vaf		$9, $9, $10
-	vaf		$13, $13, $14
-	vx		$4, $4, $1
-	vx		$8, $8, $5
-	vx		$12, $12, $9
-	vx		$16, $16, $13
-	verllf	$4, $4, 8
-	verllf	$8, $8, 8
-	verllf	$12, $12, 8
-	verllf	$16, $16, 8
+	vaf		$1(0), $1(0), $1(1)
+	vaf		$1(4), $1(4), $1(5)
+	vaf		$1(8), $1(8), $1(9)
+	vaf		$1(12), $1(12), $1(13)
+	vx		$1(3), $1(3), $1(0)
+	vx		$1(7), $1(7), $1(4)
+	vx		$1(11), $1(11), $1(8)
+	vx		$1(15), $1(15), $1(12)
+	verllf	$1(3), $1(3), 8
+	verllf	$1(7), $1(7), 8
+	verllf	$1(11), $1(11), 8
+	verllf	$1(15), $1(15), 8
 
-	vaf		$3, $3, $4
-	vaf		$7, $7, $8
-	vaf		$11, $11, $12
-	vaf		$15, $15, $16
-	vx		$2, $2, $3
-	vx		$6, $6, $7
-	vx		$10, $10, $11
-	vx		$14, $14, $15
-	verllf	$2, $2, 7
-	verllf	$6, $6, 7
-	verllf	$10, $10, 7
-	verllf	$14, $14, 7
+	vaf		$1(2), $1(2), $1(3)
+	vaf		$1(6), $1(6), $1(7)
+	vaf		$1(10), $1(10), $1(11)
+	vaf		$1(14), $1(14), $1(15)
+	vx		$1(1), $1(1), $1(2)
+	vx		$1(5), $1(5), $1(6)
+	vx		$1(9), $1(9), $1(10)
+	vx		$1(13), $1(13), $1(14)
+	verllf	$1(1), $1(1), 7
+	verllf	$1(5), $1(5), 7
+	verllf	$1(9), $1(9), 7
+	verllf	$1(13), $1(13), 7
 ')
 
 define(`TRANSPOSE',`
@@ -176,8 +183,8 @@ C Load state and splat
 	srlg	ROUNDS, ROUNDS, 1
 
 .Loop:
-	QR(%v0, %v1, %v2, %v3, %v4, %v5, %v6, %v7, %v8, %v9, %v10, %v11, %v12, %v13, %v14, %v15)
-	QR(%v0, %v5, %v10, %v15, %v4, %v9, %v14, %v3, %v8, %v13, %v2, %v7, %v12, %v1, %v6, %v11)
+	QR(`P1')
+	QR(`P2')
 	brctg	ROUNDS, .Loop
 
 	C Add in saved original words, including counters, before
