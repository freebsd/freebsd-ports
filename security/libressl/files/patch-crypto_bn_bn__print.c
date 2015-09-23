--- crypto/bn/bn_print.c.orig	2015-09-13 21:14:59 UTC
+++ crypto/bn/bn_print.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: bn_print.c,v 1.24 2015/09/13 15:59:29 deraadt Exp $ */
+/* $OpenBSD: bn_print.c,v 1.26 2015/09/18 09:00:04 sthen Exp $ */
 /* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
  * All rights reserved.
  *
@@ -114,20 +114,6 @@ BN_bn2dec(const BIGNUM *a)
 	BIGNUM *t = NULL;
 	BN_ULONG *bn_data = NULL, *lp;
 
-	if (BN_is_zero(t)) {
-		buf = malloc(BN_is_negative(t) + 2);
-		if (buf == NULL) {
-			BNerr(BN_F_BN_BN2DEC, ERR_R_MALLOC_FAILURE);
-			goto err;
-		}		
-		p = buf;
-		if (BN_is_negative(t))
-			*(p++) = '-';
-		*(p++) = '0';
-		*(p++) = '\0';
-		return (buf);
-	}
-		
 	/* get an upper bound for the length of the decimal integer
 	 * num <= (BN_num_bits(a) + 1) * log(2)
 	 *     <= 3 * BN_num_bits(a) * 0.1001 + log(2) + 1     (rounding error)
@@ -147,26 +133,31 @@ BN_bn2dec(const BIGNUM *a)
 #define BUF_REMAIN (num+3 - (size_t)(p - buf))
 	p = buf;
 	lp = bn_data;
-	if (BN_is_negative(t))
-		*p++ = '-';
+	if (BN_is_zero(t)) {
+		*(p++) = '0';
+		*(p++) = '\0';
+	} else {
+		if (BN_is_negative(t))
+			*p++ = '-';
 
-	i = 0;
-	while (!BN_is_zero(t)) {
-		*lp = BN_div_word(t, BN_DEC_CONV);
-		lp++;
-	}
-	lp--;
-	/* We now have a series of blocks, BN_DEC_NUM chars
-	 * in length, where the last one needs truncation.
-	 * The blocks need to be reversed in order. */
-	snprintf(p, BUF_REMAIN, BN_DEC_FMT1, *lp);
-	while (*p)
-		p++;
-	while (lp != bn_data) {
+		i = 0;
+		while (!BN_is_zero(t)) {
+			*lp = BN_div_word(t, BN_DEC_CONV);
+			lp++;
+		}
 		lp--;
-		snprintf(p, BUF_REMAIN, BN_DEC_FMT2, *lp);
+		/* We now have a series of blocks, BN_DEC_NUM chars
+		 * in length, where the last one needs truncation.
+		 * The blocks need to be reversed in order. */
+		snprintf(p, BUF_REMAIN, BN_DEC_FMT1, *lp);
 		while (*p)
 			p++;
+		while (lp != bn_data) {
+			lp--;
+			snprintf(p, BUF_REMAIN, BN_DEC_FMT2, *lp);
+			while (*p)
+				p++;
+		}
 	}
 	ok = 1;
 
