-- https://github.com/pola-rs/polars/issues/25977

--- crates/polars-python/src/lib.rs.orig	2026-01-06 18:40:16 UTC
+++ crates/polars-python/src/lib.rs
@@ -4,6 +4,7 @@
 #![allow(clippy::too_many_arguments)] // Python functions can have many arguments due to default arguments
 #![allow(clippy::disallowed_types)]
 #![allow(clippy::useless_conversion)] // Needed for now due to https://github.com/PyO3/pyo3/issues/4828.
+#![allow(ambiguous_glob_imports)]
 #![cfg_attr(
     feature = "allow_unused",
     allow(unused, dead_code, irrefutable_let_patterns)
