--- gwnum/gwnum.c.orig	2016-10-30 14:22:26 UTC
+++ gwnum/gwnum.c
@@ -170,7 +170,7 @@ void *avx_carries_prctab[] = {
 /*	b or blank	(b > 2 or not) */
 /*	s4 or blank	(SSE4 or not) */
 /*	k or blank	(k for XMM_K_HI is zero or not) */
-/*	c1 or cm1 or blank (c=1, c=-1, abs(c)!=1) */
+/*	c1 or cm1 or blank (c=1, c=-1, labs(c)!=1) */
 /* We also define a macro that will pick the correct entry from the array. */
 
 #define avx_explode(macro)			avx_explode1(macro,yr)			avx_explode1(macro,yi)
@@ -767,17 +767,17 @@ int gwinfo (			/* Return zero-padded fft flag or error
 	log2k = log2 (k);
 	logbk = logb (k);
 	log2b = log2 (b);
-	log2c = log2 (abs (c));
+	log2c = log2 (labs (c));
 	log2maxmulbyconst = log2 (gwdata->maxmulbyconst);
 
 /* First, see what FFT length we would get if we emulate the k*b^n+c modulo */
-/* with a zero padded FFT.  If k is 1 and abs (c) is 1 then we can skip this */
+/* with a zero padded FFT.  If k is 1 and labs (c) is 1 then we can skip this */
 /* loop as we're sure to find an IBDWT that will do the job. */
 
 again:	zpad_jmptab = NULL;
 	generic_jmptab = NULL;
 	if (! gwdata->force_general_mod &&
-	    (k > 1.0 || n < 500 || abs (c) > 1) &&
+	    (k > 1.0 || n < 500 || labs (c) > 1) &&
 	    gwdata->qa_pick_nth_fft < 1000) {
 
 /* Use the proper 2^N-1 jmptable */
@@ -984,7 +984,7 @@ next1:			while (zpad_jmptab->flags & 0x80000000) INC_J
 /* the bits per word.  An FFT result word cannot be more than 5 times */
 /* bits-per-word (bits-per-word are stored in the current word and the */
 /* 4 words we propagate carries to).  How many bits are in an FFT result */
-/* word?  Well, because of balanced representation the abs(input word) is */
+/* word?  Well, because of balanced representation the labs(input word) is */
 /* (bits_per_word-1) bits long. An FFT result word contains multiplied data */
 /* words, that's (bits_per_word-1)*2 bits.  Adding up many multiplied data */
 /* words adds some bits proportional to the size of the FFT.  Experience */
@@ -1789,13 +1789,13 @@ int gwsetup (
 
 	if (c == 0)
 		gcd = 0;
-	else if (k == 1.0 || abs (c) == 1)
+	else if (k == 1.0 || labs (c) == 1)
 		gcd = 1;
 	else {
 		stackgiant(kg,2);
 		stackgiant(cg,2);
 		dbltog (k, kg);
-		itog (abs (c), cg);
+		itog (labs (c), cg);
 		gcdg (kg, cg);
 		gcd = cg->n[0];
 	}
@@ -1809,7 +1809,7 @@ int gwsetup (
 
 	if (gcd == 1 &&
 	    k * gwdata->maxmulbyconst <= MAX_ZEROPAD_K &&
-	    abs (c) * gwdata->maxmulbyconst <= MAX_ZEROPAD_C &&
+	    labs (c) * gwdata->maxmulbyconst <= MAX_ZEROPAD_C &&
 	    log2(b) * (double) n >= 350.0 &&
 	    (b == 2 || (gwdata->cpu_flags & (CPU_AVX | CPU_SSE2))) &&
 	    !gwdata->force_general_mod) {
@@ -2429,12 +2429,12 @@ int internal_gwsetup (
 	gwdata->NUM_B_PER_SMALL_WORD = (unsigned long) gwdata->avg_num_b_per_word;
 
 /* Set a flag if this is a rational FFT.  That is, an FFT where all the */
-/* weighting factors are 1.0.  This happens when abs(c) is 1 and every */
+/* weighting factors are 1.0.  This happens when labs(c) is 1 and every */
 /* FFT word has the same number of b's.  The assembly code can make some */
 /* obvious optimizations when all the FFT weights are one. */
 
 	gwdata->RATIONAL_FFT = asm_data->RATIONAL_FFT =
-		((double) gwdata->NUM_B_PER_SMALL_WORD == gwdata->avg_num_b_per_word) && (abs (c) == 1);
+		((double) gwdata->NUM_B_PER_SMALL_WORD == gwdata->avg_num_b_per_word) && (labs (c) == 1);
 
 /* Remember the maximum number of bits per word that this FFT length */
 /* supports.  We this in gwnear_fft_limit.  Note that zero padded FFTs */
@@ -3688,7 +3688,7 @@ int internal_gwsetup (
 		if (gwdata->ZERO_PADDED_FFT ||
 		    3.0 * gwdata->NUM_B_PER_SMALL_WORD * log2 (b) >
 				2.0 * ((gwdata->NUM_B_PER_SMALL_WORD + 1) * log2 (b) - 1) +
-				0.6 * log2 (gwdata->FFTLEN) + log2 (k) + 1.7 * log2 (abs (c)))
+				0.6 * log2 (gwdata->FFTLEN) + log2 (k) + 1.7 * log2 (labs (c)))
 			asm_data->SPREAD_CARRY_OVER_EXTRA_WORDS = FALSE;
 		else
 			asm_data->SPREAD_CARRY_OVER_EXTRA_WORDS = TRUE;
@@ -6262,7 +6262,7 @@ void gw_as_string (
 		sprintf (buf, "%.0f", k + c);
 	else if (k != 1.0)
 		sprintf (buf, "%.0f*%lu^%lu%c%lu", k, b, n,
-			 c < 0 ? '-' : '+', (unsigned long) abs (c));
+			 c < 0 ? '-' : '+', (unsigned long) labs (c));
 	else if (b == 2 && c == -1)
 		sprintf (buf, "M%lu", n);
 	else {
@@ -6272,7 +6272,7 @@ void gw_as_string (
 			sprintf (buf, "F%lu", cnt);
 		else
 			sprintf (buf, "%lu^%lu%c%lu", b, n,
-				 c < 0 ? '-' : '+', (unsigned long) abs (c));
+				 c < 0 ? '-' : '+', (unsigned long) labs (c));
 	}
 }
 
@@ -6357,7 +6357,7 @@ double virtual_bits_per_word (
 		weighted_bits_per_output_word =
 			2.0 * ((b_per_input_word + 1.0) * log2b - 1.0) +
 			0.6 * log2 (gwdata->FFTLEN) +
-			log2 (gwdata->k) + 1.7 * log2 (abs (gwdata->c));
+			log2 (gwdata->k) + 1.7 * log2 (labs (gwdata->c));
 		if (gwdata->k == 1.0 && gwdata->n % gwdata->FFTLEN == 0)
 			weighted_bits_per_output_word -= ((log2b <= 4.0) ? log2b : 1.4 * log2b);
 		else if (num_big_words == 1 && gwdata->k > 1.0)
@@ -6756,7 +6756,7 @@ void gwsetaddin (
 {
 	unsigned long word, b_in_word;
 
-	ASSERTG (gwdata->k == 1.0 || abs (gwdata->c) == 1);
+	ASSERTG (gwdata->k == 1.0 || labs (gwdata->c) == 1);
 
 /* In a zero-padded FFT, the value is added into ZPAD0 */
 
@@ -7022,7 +7022,7 @@ void gianttogw (
 /* Small numbers can also be optimized for many moduli by zeroing all the */
 /* FFT data using memset and then setting only the affected FFT elements. */
 
-	else if (a->sign == 1 && (gwdata->k == 1.0 || abs (gwdata->c) == 1)) {
+	else if (a->sign == 1 && (gwdata->k == 1.0 || labs (gwdata->c) == 1)) {
 		uint32_t low_addin;
 		int	i;
 
@@ -7639,7 +7639,7 @@ void specialmodg (
 	}
 
 /* Do the quick modulus code twice because in the case where */
-/* abs(c) > k once won't get us close enough. */
+/* labs(c) > k once won't get us close enough. */
 
 	neg = FALSE;
 	for (count = 0; count < 2; count++) {
@@ -7647,7 +7647,7 @@ void specialmodg (
 /* Handle negative input values */
 
 	    neg ^= (g->sign < 0);
-	    g->sign = abs (g->sign);
+	    g->sign = labs (g->sign);
 
 /* If number is bigger than the modulus, do a mod using shifts and adds */
 /* This will get us close to the right answer. */
