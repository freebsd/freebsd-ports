-- https://github.com/pola-rs/polars/issues/25977

--- crates/polars-sql/src/functions.rs.orig	2026-10-06 06:15:22 UTC
+++ crates/polars-sql/src/functions.rs
@@ -11,6 +11,7 @@ use polars_lazy::prelude::ApproxQuantileMethod;
 use polars_lazy::dsl::Expr;
 #[cfg(feature = "approx_quantile")]
 use polars_lazy::prelude::ApproxQuantileMethod;
+#[allow(ambiguous_glob_imports)]
 use polars_plan::dsl::functions::{
     coalesce, col, cols, concat_str, element, int_range, len, lit, max_horizontal, min_horizontal,
     when,
