--- rust/vendor/lexical-core/src/atof/algorithm/bhcomp.rs.orig	2021-06-19 12:41:29 UTC
+++ rust/vendor/lexical-core/src/atof/algorithm/bhcomp.rs
@@ -59,7 +59,7 @@ pub(super) fn parse_mantissa<'a, Data>(data: Data, rad
     let small_powers = Bigint::small_powers(radix);
     let count = data.mantissa_digits();
     let bits = count / integral_binary_factor(radix).as_usize();
-    let bytes = bits / Limb::BITS;
+    let bytes = bits / <Limb as Integer>::BITS;
 
     // Main loop
     let step = small_powers.len() - 2;
