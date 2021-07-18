--- cargo-crates/lexical-core-0.4.2/src/atof/algorithm/bigint.rs.orig	2021-06-19 12:08:24 UTC
+++ cargo-crates/lexical-core-0.4.2/src/atof/algorithm/bigint.rs
@@ -81,7 +81,7 @@ pub(super) fn parse_mantissa(slc: FloatSlice, radix: u
     let small_powers = Bigint::small_powers(radix);
     let count = slc.mantissa_digits();
     let bits = count / integral_binary_factor(radix).as_usize();
-    let bytes = bits / Limb::BITS;
+    let bytes = bits / <Limb as Integer>::BITS;
 
     // Main loop
     let step = small_powers.len() - 2;
