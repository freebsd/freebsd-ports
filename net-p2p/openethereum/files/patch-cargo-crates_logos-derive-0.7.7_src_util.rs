--- cargo-crates/logos-derive-0.7.7/src/util.rs.orig	2021-06-19 20:26:00 UTC
+++ cargo-crates/logos-derive-0.7.7/src/util.rs
@@ -3,11 +3,11 @@ pub use proc_macro2::{Span, TokenTree};
 use quote::quote;
 
 pub trait OptionExt<T> {
-    fn insert(&mut self, val: T, f: impl FnOnce(&T));
+    fn insert_or(&mut self, val: T, f: impl FnOnce(&T));
 }
 
 impl<T> OptionExt<T> for Option<T> {
-    fn insert(&mut self, val: T, f: impl FnOnce(&T)) {
+    fn insert_or(&mut self, val: T, f: impl FnOnce(&T)) {
         match self {
             Some(t) => f(t),
             slot    => *slot = Some(val),
