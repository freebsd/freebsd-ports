--- cargo-crates/lexical-core-0.4.2/src/atof/algorithm/math.rs.orig	2021-06-19 12:08:38 UTC
+++ cargo-crates/lexical-core-0.4.2/src/atof/algorithm/math.rs
@@ -952,7 +952,7 @@ pub fn mul(x: Limb, y: Limb, carry: Limb)
     // the following is always true:
     // `Wide::max_value() - (Narrow::max_value() * Narrow::max_value()) >= Narrow::max_value()`
     let z: Wide = as_wide(x) * as_wide(y) + as_wide(carry);
-    (as_limb(z), as_limb(z >> Limb::BITS))
+    (as_limb(z), as_limb(z >> <Limb as Integer>::BITS))
 }
 
 /// Multiply two small integers (with carry) (and return if overflow happens).
@@ -975,7 +975,7 @@ pub fn div(x: Limb, y: Limb, rem: Limb)
     -> (Limb, Limb)
 {
     // Cannot overflow, as long as wide is 2x as wide.
-    let x = as_wide(x) | (as_wide(rem) << Limb::BITS);
+    let x = as_wide(x) | (as_wide(rem) << <Limb as Integer>::BITS);
     let y = as_wide(y);
     (as_limb(x / y), as_limb(x % y))
 }
@@ -1042,7 +1042,7 @@ pub fn leading_zeros(x: &[Limb]) -> usize {
 pub fn trailing_zeros(x: &[Limb]) -> usize {
     // Get the index of the last non-zero value
     let index = trailing_zero_limbs(x);
-    let mut count = index.saturating_mul(Limb::BITS);
+    let mut count = index.saturating_mul(<Limb as Integer>::BITS);
     if let Some(value) = x.get(index) {
         count = count.saturating_add(value.trailing_zeros().as_usize());
     }
@@ -1057,7 +1057,7 @@ pub fn bit_length(x: &[Limb]) -> usize {
     // Avoid overflowing, calculate via total number of bits
     // minus leading zero bits.
     let nlz = leading_zeros(x);
-    Limb::BITS.checked_mul(x.len())
+    <Limb as Integer>::BITS.checked_mul(x.len())
         .map(|v| v - nlz)
         .unwrap_or(usize::max_value())
 }
@@ -1076,14 +1076,14 @@ pub fn limb_length(x: &[Limb]) -> usize {
 ///
 /// Returns the truncated bits.
 ///
-/// Assumes `n < Limb::BITS`, IE, internally shifting bits.
+/// Assumes `n < <Limb as Integer>::BITS`, IE, internally shifting bits.
 #[inline]
 pub fn ishr_bits<T>(x: &mut T, n: usize)
     -> Limb
     where T: CloneableVecLike<Limb>
 {
-    // Need to shift by the number of `bits % Limb::BITS`.
-    let bits = Limb::BITS;
+    // Need to shift by the number of `bits % <Limb as Integer>::BITS`.
+    let bits = <Limb as Integer>::BITS;
     debug_assert!(n < bits && n != 0);
 
     // Internally, for each item, we shift left by n, and add the previous
@@ -1129,9 +1129,9 @@ pub fn ishr<T>(x: &mut T, n: usize)
     -> bool
     where T: CloneableVecLike<Limb>
 {
-    let bits = Limb::BITS;
-    // Need to pad with zeros for the number of `bits / Limb::BITS`,
-    // and shift-left with carry for `bits % Limb::BITS`.
+    let bits = <Limb as Integer>::BITS;
+    // Need to pad with zeros for the number of `bits / <Limb as Integer>::BITS`,
+    // and shift-left with carry for `bits % <Limb as Integer>::BITS`.
     let rem = n % bits;
     let div = n / bits;
     let is_zero = match div.is_zero() {
@@ -1182,13 +1182,13 @@ pub fn shr<T>(x: &[Limb], n: usize)
 
 /// Shift-left bits inside a buffer.
 ///
-/// Assumes `n < Limb::BITS`, IE, internally shifting bits.
+/// Assumes `n < <Limb as Integer>::BITS`, IE, internally shifting bits.
 #[inline]
 pub fn ishl_bits<T>(x: &mut T, n: usize)
     where T: CloneableVecLike<Limb>
 {
-    // Need to shift by the number of `bits % Limb::BITS)`.
-    let bits = Limb::BITS;
+    // Need to shift by the number of `bits % <Limb as Integer>::BITS)`.
+    let bits = <Limb as Integer>::BITS;
     debug_assert!(n < bits);
     if n.is_zero() {
         return;
@@ -1218,7 +1218,7 @@ pub fn ishl_bits<T>(x: &mut T, n: usize)
 
 /// Shift-left bits inside a buffer.
 ///
-/// Assumes `n < Limb::BITS`, IE, internally shifting bits.
+/// Assumes `n < <Limb as Integer>::BITS`, IE, internally shifting bits.
 #[inline]
 pub fn shl_bits<T>(x: &[Limb], n: usize)
     -> T
@@ -1248,9 +1248,9 @@ pub fn ishl_limbs<T>(x: &mut T, n: usize)
 pub fn ishl<T>(x: &mut T, n: usize)
     where T: CloneableVecLike<Limb>
 {
-    let bits = Limb::BITS;
-    // Need to pad with zeros for the number of `bits / Limb::BITS`,
-    // and shift-left with carry for `bits % Limb::BITS`.
+    let bits = <Limb as Integer>::BITS;
+    // Need to pad with zeros for the number of `bits / <Limb as Integer>::BITS`,
+    // and shift-left with carry for `bits % <Limb as Integer>::BITS`.
     let rem = n % bits;
     let div = n / bits;
     ishl_bits(x, rem);
@@ -1903,7 +1903,7 @@ pub fn mul<T>(x: &[Limb], y: &[Limb])
 // DIVISION
 
 /// Constants for algorithm D.
-const ALGORITHM_D_B: Wide = 1 << Limb::BITS;
+const ALGORITHM_D_B: Wide = 1 << <Limb as Integer>::BITS;
 const ALGORITHM_D_M: Wide = ALGORITHM_D_B - 1;
 
 /// Calculate qhat (an estimate for the quotient).
@@ -1924,7 +1924,7 @@ fn calculate_qhat(x: &[Limb], y: &[Limb], j: usize)
     //  rhat = (x[j+n]*B + x[j+n-1]) - qhat*y[n-1];
     let x_jn = as_wide(x[j+n]);
     let x_jn1 = as_wide(x[j+n-1]);
-    let num = (x_jn << Limb::BITS) + x_jn1;
+    let num = (x_jn << <Limb as Integer>::BITS) + x_jn1;
     let den = as_wide(y[n-1]);
     let mut qhat = num / den;
     let mut rhat = num - qhat * den;
@@ -1941,7 +1941,7 @@ fn calculate_qhat(x: &[Limb], y: &[Limb], j: usize)
     let y_n2 = as_wide(y[n-2]);
     let y_n1 = as_wide(y[n-1]);
     // This only happens when the leading bit of qhat is set.
-    while qhat >= ALGORITHM_D_B || qhat * y_n2 > (rhat << Limb::BITS) + x_jn2 {
+    while qhat >= ALGORITHM_D_B || qhat * y_n2 > (rhat << <Limb as Integer>::BITS) + x_jn2 {
         qhat -= 1;
         rhat += y_n1;
         if rhat >= ALGORITHM_D_B {
@@ -1982,7 +1982,7 @@ fn multiply_and_subtract<T>(x: &mut T, y: &T, qhat: Wi
         let p = qhat * y_i;
         t = x_ij.wrapping_sub(k).wrapping_sub(as_signed_wide(p & ALGORITHM_D_M));
         x[i+j] = as_limb(t);
-        k = as_signed_wide(p >> Limb::BITS) - (t >> Limb::BITS);
+        k = as_signed_wide(p >> <Limb as Integer>::BITS) - (t >> <Limb as Integer>::BITS);
     }
     t = as_signed_wide(x[j+n]) - k;
     x[j+n] = as_limb(t);
@@ -2039,7 +2039,7 @@ fn add_back<T>(x: &mut T, y: &T, mut t: SignedWide, j:
         for i in 0..n {
             t = as_signed_wide(as_wide(x[i+j]) + as_wide(y[i])) + k;
             x[i+j] = as_limb(t);
-            k = t >> Limb::BITS;
+            k = t >> <Limb as Integer>::BITS;
         }
         let x_jn = as_signed_wide(x[j+n]) + k;
         x[j+n] = as_limb(x_jn);
@@ -2063,7 +2063,7 @@ fn calculate_remainder<T>(x: &[Limb], y: &[Limb], s: u
     let n = y.len();
     let mut r = T::default();
     r.reserve_exact(n);
-    let rs = Limb::BITS - s;
+    let rs = <Limb as Integer>::BITS - s;
     for i in 0..n-1 {
         let xi = as_wide(x[i]) >> s;
         let xi1 = as_wide(x[i+1]) << rs;
@@ -2199,9 +2199,9 @@ pub fn quorem<T>(x: &mut T, y: &T)
         let mut carry: Wide = 0;
         for j in 0..m {
             let p = as_wide(y[j]) * as_wide(q) + carry;
-            carry = p >> Limb::BITS;
+            carry = p >> <Limb as Integer>::BITS;
             let t = as_wide(x[j]).wrapping_sub(p & mask).wrapping_sub(borrow);
-            borrow = (t >> Limb::BITS) & 1;
+            borrow = (t >> <Limb as Integer>::BITS) & 1;
             x[j] = as_limb(t);
         }
         small::normalize(x);
@@ -2214,9 +2214,9 @@ pub fn quorem<T>(x: &mut T, y: &T)
         let mut carry: Wide = 0;
         for j in 0..m {
             let p = as_wide(y[j]) + carry;
-            carry = p >> Limb::BITS;
+            carry = p >> <Limb as Integer>::BITS;
             let t = as_wide(x[j]).wrapping_sub(p & mask).wrapping_sub(borrow);
-            borrow = (t >> Limb::BITS) & 1;
+            borrow = (t >> <Limb as Integer>::BITS) & 1;
             x[j] = as_limb(t);
         }
         small::normalize(x);
@@ -3126,18 +3126,18 @@ mod tests {
     fn leading_zeros_test() {
         assert_eq!(Bigint::new().leading_zeros(), 0);
 
-        assert_eq!(Bigint::from_u16(0xFF).leading_zeros(), Limb::BITS-8);
-        assert_eq!(Bigint::from_u32(0xFF).leading_zeros(), Limb::BITS-8);
+        assert_eq!(Bigint::from_u16(0xFF).leading_zeros(), <Limb as Integer>::BITS-8);
+        assert_eq!(Bigint::from_u32(0xFF).leading_zeros(), <Limb as Integer>::BITS-8);
         assert_eq!(Bigint::from_u64(0xFF00000000).leading_zeros(), 24);
         assert_eq!(Bigint::from_u128(0xFF000000000000000000000000).leading_zeros(), 24);
 
-        assert_eq!(Bigint::from_u16(0xF).leading_zeros(), Limb::BITS-4);
-        assert_eq!(Bigint::from_u32(0xF).leading_zeros(), Limb::BITS-4);
+        assert_eq!(Bigint::from_u16(0xF).leading_zeros(), <Limb as Integer>::BITS-4);
+        assert_eq!(Bigint::from_u32(0xF).leading_zeros(), <Limb as Integer>::BITS-4);
         assert_eq!(Bigint::from_u64(0xF00000000).leading_zeros(), 28);
         assert_eq!(Bigint::from_u128(0xF000000000000000000000000).leading_zeros(), 28);
 
-        assert_eq!(Bigint::from_u16(0xF0).leading_zeros(), Limb::BITS-8);
-        assert_eq!(Bigint::from_u32(0xF0).leading_zeros(), Limb::BITS-8);
+        assert_eq!(Bigint::from_u16(0xF0).leading_zeros(), <Limb as Integer>::BITS-8);
+        assert_eq!(Bigint::from_u32(0xF0).leading_zeros(), <Limb as Integer>::BITS-8);
         assert_eq!(Bigint::from_u64(0xF000000000).leading_zeros(), 24);
         assert_eq!(Bigint::from_u128(0xF0000000000000000000000000).leading_zeros(), 24);
     }
