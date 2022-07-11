Obtained from:	https://git.lysator.liu.se/nettle/nettle/-/commit/d4c7597e4236f746434c9a1a24f6191f7ff870cd

--- arm64/chacha-4core.asm.orig	2022-06-02 17:57:16 UTC
+++ arm64/chacha-4core.asm
@@ -53,67 +53,74 @@ define(`TMP3', `v7')
 
 define(`ROT24', `v8')
 
+C A workaround for expanding multiple digits of argument references to QR macro which is incompatible with POSIX
+C See https://www.gnu.org/software/m4/manual/html_node/Arguments.html
+define(`P1',
+`ifelse($1, 0, v16, $1, 1, v17, $1, 2, v18, $1, 3, v19, $1, 4, v20, $1, 5, v21, $1, 6, v22, $1, 7, v23, $1, 8, v24, $1, 9, v25, $1, 10, v26, $1, 11, v27, $1, 12, v28, $1, 13, v29, $1, 14, v30, $1, 15, v31)')
+define(`P2',
+`ifelse($1, 0, v16, $1, 1, v21, $1, 2, v26, $1, 3, v31, $1, 4, v20, $1, 5, v25, $1, 6, v30, $1, 7, v19, $1, 8, v24, $1, 9, v29, $1, 10, v18, $1, 11, v23, $1, 12, v28, $1, 13, v17, $1, 14, v22, $1, 15, v27)')
+
 C Main loop for round
 define(`QR',`
-	add		$1.4s, $1.4s, $2.4s
-	add		$5.4s, $5.4s, $6.4s
-	add		$9.4s, $9.4s, $10.4s
-	add		$13.4s, $13.4s, $14.4s
-	eor		$4.16b, $4.16b, $1.16b
-	eor		$8.16b, $8.16b, $5.16b
-	eor		$12.16b, $12.16b, $9.16b
-	eor		$16.16b, $16.16b, $13.16b
-	rev32	$4.8h, $4.8h
-	rev32	$8.8h, $8.8h
-	rev32	$12.8h, $12.8h
-	rev32	$16.8h, $16.8h
+	add		$1(0).4s, $1(0).4s, $1(1).4s
+	add		$1(4).4s, $1(4).4s, $1(5).4s
+	add		$1(8).4s, $1(8).4s, $1(9).4s
+	add		$1(12).4s, $1(12).4s, $1(13).4s
+	eor		$1(3).16b, $1(3).16b, $1(0).16b
+	eor		$1(7).16b, $1(7).16b, $1(4).16b
+	eor		$1(11).16b, $1(11).16b, $1(8).16b
+	eor		$1(15).16b, $1(15).16b, $1(12).16b
+	rev32	$1(3).8h, $1(3).8h
+	rev32	$1(7).8h, $1(7).8h
+	rev32	$1(11).8h, $1(11).8h
+	rev32	$1(15).8h, $1(15).8h
 
-	add		$3.4s, $3.4s, $4.4s
-	add		$7.4s, $7.4s, $8.4s
-	add		$11.4s, $11.4s, $12.4s
-	add		$15.4s, $15.4s, $16.4s
-	eor		TMP0.16b, $2.16b, $3.16b
-	eor		TMP1.16b, $6.16b, $7.16b
-	eor		TMP2.16b, $10.16b, $11.16b
-	eor		TMP3.16b, $14.16b, $15.16b
-	ushr	$2.4s, TMP0.4s, #20
-	ushr	$6.4s, TMP1.4s, #20
-	ushr	$10.4s, TMP2.4s, #20
-	ushr	$14.4s, TMP3.4s, #20
-	sli		$2.4s, TMP0.4s, #12
-	sli		$6.4s, TMP1.4s, #12
-	sli		$10.4s, TMP2.4s, #12
-	sli		$14.4s, TMP3.4s, #12
+	add		$1(2).4s, $1(2).4s, $1(3).4s
+	add		$1(6).4s, $1(6).4s, $1(7).4s
+	add		$1(10).4s, $1(10).4s, $1(11).4s
+	add		$1(14).4s, $1(14).4s, $1(15).4s
+	eor		TMP0.16b, $1(1).16b, $1(2).16b
+	eor		TMP1.16b, $1(5).16b, $1(6).16b
+	eor		TMP2.16b, $1(9).16b, $1(10).16b
+	eor		TMP3.16b, $1(13).16b, $1(14).16b
+	ushr	$1(1).4s, TMP0.4s, #20
+	ushr	$1(5).4s, TMP1.4s, #20
+	ushr	$1(9).4s, TMP2.4s, #20
+	ushr	$1(13).4s, TMP3.4s, #20
+	sli		$1(1).4s, TMP0.4s, #12
+	sli		$1(5).4s, TMP1.4s, #12
+	sli		$1(9).4s, TMP2.4s, #12
+	sli		$1(13).4s, TMP3.4s, #12
 
-	add		$1.4s, $1.4s, $2.4s
-	add		$5.4s, $5.4s, $6.4s
-	add		$9.4s, $9.4s, $10.4s
-	add		$13.4s, $13.4s, $14.4s
-	eor		$4.16b, $4.16b, $1.16b
-	eor		$8.16b, $8.16b, $5.16b
-	eor		$12.16b, $12.16b, $9.16b
-	eor		$16.16b, $16.16b, $13.16b
-	tbl		$4.16b, {$4.16b}, ROT24.16b
-	tbl		$8.16b, {$8.16b}, ROT24.16b
-	tbl		$12.16b, {$12.16b}, ROT24.16b
-	tbl		$16.16b, {$16.16b}, ROT24.16b
+	add		$1(0).4s, $1(0).4s, $1(1).4s
+	add		$1(4).4s, $1(4).4s, $1(5).4s
+	add		$1(8).4s, $1(8).4s, $1(9).4s
+	add		$1(12).4s, $1(12).4s, $1(13).4s
+	eor		$1(3).16b, $1(3).16b, $1(0).16b
+	eor		$1(7).16b, $1(7).16b, $1(4).16b
+	eor		$1(11).16b, $1(11).16b, $1(8).16b
+	eor		$1(15).16b, $1(15).16b, $1(12).16b
+	tbl		$1(3).16b, {$1(3).16b}, ROT24.16b
+	tbl		$1(7).16b, {$1(7).16b}, ROT24.16b
+	tbl		$1(11).16b, {$1(11).16b}, ROT24.16b
+	tbl		$1(15).16b, {$1(15).16b}, ROT24.16b
 
-	add		$3.4s, $3.4s, $4.4s
-	add		$7.4s, $7.4s, $8.4s
-	add		$11.4s, $11.4s, $12.4s
-	add		$15.4s, $15.4s, $16.4s
-	eor		TMP0.16b, $2.16b, $3.16b
-	eor		TMP1.16b, $6.16b, $7.16b
-	eor		TMP2.16b, $10.16b, $11.16b
-	eor		TMP3.16b, $14.16b, $15.16b
-	ushr	$2.4s, TMP0.4s, #25
-	ushr	$6.4s, TMP1.4s, #25
-	ushr	$10.4s, TMP2.4s, #25
-	ushr	$14.4s, TMP3.4s, #25
-	sli		$2.4s, TMP0.4s, #7
-	sli		$6.4s, TMP1.4s, #7
-	sli		$10.4s, TMP2.4s, #7
-	sli		$14.4s, TMP3.4s, #7
+	add		$1(2).4s, $1(2).4s, $1(3).4s
+	add		$1(6).4s, $1(6).4s, $1(7).4s
+	add		$1(10).4s, $1(10).4s, $1(11).4s
+	add		$1(14).4s, $1(14).4s, $1(15).4s
+	eor		TMP0.16b, $1(1).16b, $1(2).16b
+	eor		TMP1.16b, $1(5).16b, $1(6).16b
+	eor		TMP2.16b, $1(9).16b, $1(10).16b
+	eor		TMP3.16b, $1(13).16b, $1(14).16b
+	ushr	$1(1).4s, TMP0.4s, #25
+	ushr	$1(5).4s, TMP1.4s, #25
+	ushr	$1(9).4s, TMP2.4s, #25
+	ushr	$1(13).4s, TMP3.4s, #25
+	sli		$1(1).4s, TMP0.4s, #7
+	sli		$1(5).4s, TMP1.4s, #7
+	sli		$1(9).4s, TMP2.4s, #7
+	sli		$1(13).4s, TMP3.4s, #7
 ')
 
 define(`TRANSPOSE',`
@@ -174,8 +181,8 @@ C Load state and splat
 	mov		T3.16b, v31.16b
 
 .Loop:
-	QR(v16, v17,  v18, v19, v20, v21,  v22, v23, v24, v25, v26, v27, v28, v29, v30, v31)
-	QR(v16, v21, v26, v31, v20, v25, v30, v19, v24, v29,  v18, v23, v28, v17,  v22, v27)
+	QR(`P1')
+	QR(`P2')
 	subs	ROUNDS, ROUNDS, #2
 	b.ne	.Loop
 
