--- gwnum/gwnum.c.orig	2016-10-30 14:22:26 UTC
+++ gwnum/gwnum.c
@@ -865,17 +865,17 @@
 	log2k = log2 (k);
 	logbk = logb (k);
 	log2b = log2 (b);
-	log2c = log2 (abs (c));
+	log2c = log2 (labs (c));
 	log2maxmulbyconst = log2 (gwdata->maxmulbyconst);
 
 /* First, see what FFT length we would get if we emulate the k*b^n+c modulo */
-/* with a zero padded FFT.  If k is 1 and abs (c) is 1 then we can skip this */
+/* with a zero padded FFT.  If k is 1 and labs (c) is 1 then we can skip this */
 /* loop as we're sure to find an IBDWT that will do the job. Also skip if called from */
 /* gwmap_fftlen_to_max_exponent (n = 0) or we are QAing IBDWT FFTs (qa_pick_nth_fft >= 1000) */
 
 again:	zpad_jmptab = NULL;
 	generic_jmptab = NULL;
-	if (! gwdata->force_general_mod && (k > 1.0 || (n > 0 && n < 500) || abs (c) > 1) && gwdata->qa_pick_nth_fft < 1000) {
+	if (! gwdata->force_general_mod && (k > 1.0 || (n > 0 && n < 500) || labs (c) > 1) && gwdata->qa_pick_nth_fft < 1000) {
 
 /* Use the proper 2^N-1 jmptable */
 
@@ -1915,13 +1915,13 @@
 
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
@@ -1935,7 +1935,7 @@
 
 	if (gcd == 1 &&
 	    k * gwdata->maxmulbyconst <= MAX_ZEROPAD_K &&
-	    abs (c) * gwdata->maxmulbyconst <= MAX_ZEROPAD_C &&
+	    labs (c) * gwdata->maxmulbyconst <= MAX_ZEROPAD_C &&
 	    log2(b) * (double) n >= 350.0 &&
 	    (b == 2 || (gwdata->cpu_flags & (CPU_AVX | CPU_SSE2))) &&
 	    !gwdata->force_general_mod) {
@@ -2555,12 +2555,12 @@
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
@@ -3814,7 +3814,7 @@
 		if (gwdata->ZERO_PADDED_FFT ||
 		    3.0 * gwdata->NUM_B_PER_SMALL_WORD * log2 (b) >
 				2.0 * ((gwdata->NUM_B_PER_SMALL_WORD + 1) * log2 (b) - 1) +
-				0.6 * log2 (gwdata->FFTLEN) + log2 (k) + 1.7 * log2 (abs (c)))
+				0.6 * log2 (gwdata->FFTLEN) + log2 (k) + 1.7 * log2 (labs (c)))
 			asm_data->SPREAD_CARRY_OVER_EXTRA_WORDS = FALSE;
 		else
 			asm_data->SPREAD_CARRY_OVER_EXTRA_WORDS = TRUE;
@@ -6409,7 +6409,7 @@
 		sprintf (buf, "%.0f", k + c);
 	else if (k != 1.0)
 		sprintf (buf, "%.0f*%lu^%lu%c%lu", k, b, n,
-			 c < 0 ? '-' : '+', (unsigned long) abs (c));
+			 c < 0 ? '-' : '+', (unsigned long) labs (c));
 	else if (b == 2 && c == -1)
 		sprintf (buf, "M%lu", n);
 	else {
@@ -6419,7 +6419,7 @@
 			sprintf (buf, "F%lu", cnt);
 		else
 			sprintf (buf, "%lu^%lu%c%lu", b, n,
-				 c < 0 ? '-' : '+', (unsigned long) abs (c));
+				 c < 0 ? '-' : '+', (unsigned long) labs (c));
 	}
 }
 
@@ -6504,7 +6504,7 @@
 		weighted_bits_per_output_word =
 			2.0 * ((b_per_input_word + 1.0) * log2b - 1.0) +
 			0.6 * log2 (gwdata->FFTLEN) +
-			log2 (gwdata->k) + 1.7 * log2 (abs (gwdata->c));
+			log2 (gwdata->k) + 1.7 * log2 (labs (gwdata->c));
 		if (gwdata->k == 1.0 && gwdata->n % gwdata->FFTLEN == 0)
 			weighted_bits_per_output_word -= ((log2b <= 4.0) ? log2b : 1.4 * log2b);
 		else if (num_big_words == 1 && gwdata->k > 1.0)
@@ -6911,7 +6911,7 @@
 {
 	unsigned long word, b_in_word;
 
-	ASSERTG (gwdata->k == 1.0 || abs (gwdata->c) == 1);
+	ASSERTG (gwdata->k == 1.0 || labs (gwdata->c) == 1);
 
 /* In a zero-padded FFT, the value is added into ZPAD0 */
 
@@ -7177,7 +7177,7 @@
 /* Small numbers can also be optimized for many moduli by zeroing all the */
 /* FFT data using memset and then setting only the affected FFT elements. */
 
-	else if (a->sign == 1 && (gwdata->k == 1.0 || abs (gwdata->c) == 1)) {
+	else if (a->sign == 1 && (gwdata->k == 1.0 || labs (gwdata->c) == 1)) {
 		uint32_t low_addin;
 		int	i;
 
@@ -7802,7 +7802,7 @@
 /* Handle negative input values */
 
 	    neg ^= (g->sign < 0);
-	    g->sign = abs (g->sign);
+	    g->sign = labs (g->sign);
 
 /* If number is bigger than the modulus, do a mod using shifts and adds */
 /* This will get us close to the right answer. */
