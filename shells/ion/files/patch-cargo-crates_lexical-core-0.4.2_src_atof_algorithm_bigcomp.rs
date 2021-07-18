error[E0308]: mismatched types
   --> cargo-crates/lexical-core-0.4.2/src/atof/algorithm/bigcomp.rs:242:55
    |
242 |     let nlz = den.leading_zeros().wrapping_sub(wlz) & (u32::BITS - 1);
    |                                                       ^^^^^^^^^^^^^^^ expected `usize`, found `u32`

error[E0277]: no implementation for `usize & u32`

https://github.com/Alexhuszagh/rust-lexical/commit/05f2cf96b080a81e2bee1f30ae389dc4f9cb6d00

--- cargo-crates/lexical-core-0.4.2/src/atof/algorithm/bigcomp.rs.orig	2021-06-19 11:52:10 UTC
+++ cargo-crates/lexical-core-0.4.2/src/atof/algorithm/bigcomp.rs
@@ -239,7 +239,7 @@ pub(super) fn make_ratio<F: Float>(radix: u32, sci_exp
     // Scale the denominator so it has the number of bits
     // in the radix as the number of leading zeros.
     let wlz = integral_binary_factor(radix).as_usize();
-    let nlz = den.leading_zeros().wrapping_sub(wlz) & (u32::BITS - 1);
+    let nlz = den.leading_zeros().wrapping_sub(wlz) & (<u32 as Integer>::BITS - 1);
     small::ishl_bits(den.data_mut(), nlz);
     den.exp -= nlz.as_i32();
 
@@ -257,7 +257,7 @@ pub(super) fn make_ratio<F: Float>(radix: u32, sci_exp
         // denominator will be normalized.
         // We need to add one to the quotient,since we're calculating the
         // ceiling of the divmod.
-        let (q, r) = shift.ceil_divmod(Limb::BITS);
+        let (q, r) = shift.ceil_divmod(<Limb as Integer>::BITS);
         // Since we're using a power from the denominator to the
         // numerator, we to invert r, not add u32::BITS.
         let r = -r;
@@ -265,7 +265,7 @@ pub(super) fn make_ratio<F: Float>(radix: u32, sci_exp
         num.exp -= r;
         if !q.is_zero() {
             den.pad_zero_digits(q);
-            den.exp -= Limb::BITS.as_i32() * q.as_i32();
+            den.exp -= <Limb as Integer>::BITS.as_i32() * q.as_i32();
         }
     }
 
