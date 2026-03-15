-- https://github.com/pola-rs/polars/issues/25977

--- crates/polars-sql/src/functions.rs.orig	2026-03-12 10:40:39 UTC
+++ crates/polars-sql/src/functions.rs
@@ -10,6 +10,7 @@ use polars_ops::series::RoundMode;
 use polars_lazy::prelude::{RankMethod, RankOptions};
 use polars_ops::chunked_array::UnicodeForm;
 use polars_ops::series::RoundMode;
+#[allow(ambiguous_glob_imports)]
 use polars_plan::dsl::functions::{
     as_struct, coalesce, col, cols, concat_str, element, int_range, len, lit, max_horizontal,
     min_horizontal, when,
