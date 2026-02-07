-- https://github.com/pola-rs/polars/issues/25977

--- crates/polars-sql/src/functions.rs.orig	2026-01-06 18:25:53 UTC
+++ crates/polars-sql/src/functions.rs
@@ -10,6 +10,7 @@ use polars_ops::series::RoundMode;
 use polars_lazy::prelude::{RankMethod, RankOptions};
 use polars_ops::chunked_array::UnicodeForm;
 use polars_ops::series::RoundMode;
+#[allow(ambiguous_glob_imports)]
 use polars_plan::dsl::{
     as_struct, coalesce, concat_str, element, int_range, len, max_horizontal, min_horizontal, when,
 };
