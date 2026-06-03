-- https://github.com/pola-rs/polars/issues/25977

--- crates/polars-sql/src/lib.rs.orig	2026-01-06 18:31:54 UTC
+++ crates/polars-sql/src/lib.rs
@@ -1,6 +1,7 @@
 //! Polars SQL
 //! This crate provides a SQL interface for Polars DataFrames
 #![deny(missing_docs)]
+#![allow(ambiguous_glob_imports)]
 mod context;
 pub mod function_registry;
 mod functions;
