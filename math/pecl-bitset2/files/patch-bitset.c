--- bitset.c.orig	2017-10-06 16:29:59 UTC
+++ bitset.c
@@ -652,7 +652,7 @@ PHP_METHOD(BitSet, previousClearBit)
 	bit_diff = intern->bitset_len * CHAR_BIT;
 
 	if (start_bit > bit_diff) {
-		zend_throw_exception_ex(spl_ce_OutOfRangeException, 0,
+		zend_throw_exception_ex(spl_ce_OutOfRangeException, 0 TSRMLS_CC,
 								"The specified index parameter exceeds the total number of bits available");
 		return;
 	}
@@ -696,7 +696,7 @@ PHP_METHOD(BitSet, previousSetBit)
 	bit_diff = intern->bitset_len * CHAR_BIT;
 
 	if (start_bit > bit_diff) {
-		zend_throw_exception_ex(spl_ce_OutOfRangeException, 0,
+		zend_throw_exception_ex(spl_ce_OutOfRangeException, 0 TSRMLS_CC,
 								"The specified index parameter exceeds the total number of bits available");
 	}
 
