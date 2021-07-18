error[E0061]: this function takes 1 argument but 2 arguments were supplied
   --> cargo-crates/logos-derive-0.7.7/src/lib.rs:55:20
    |
55  |             extras.insert(util::ident(&ext), |_| panic!("Only one #[extras] attribute can be declared."));
    |                    ^^^^^^ -----------------  ----------------------------------------------------------- supplied 2 arguments
    |                    |
    |                    expected 1 argument
    |

--- cargo-crates/logos-derive-0.7.7/src/lib.rs.orig	2021-06-19 19:31:53 UTC
+++ cargo-crates/logos-derive-0.7.7/src/lib.rs
@@ -52,7 +52,7 @@ pub fn logos(input: TokenStream) -> TokenStream {
 
     for attr in &item.attrs {
         if let Some(ext) = value_from_attr("extras", attr) {
-            extras.insert(util::ident(&ext), |_| panic!("Only one #[extras] attribute can be declared."));
+            extras.insert_or(util::ident(&ext), |_| panic!("Only one #[extras] attribute can be declared."));
         }
     }
 
@@ -86,11 +86,11 @@ pub fn logos(input: TokenStream) -> TokenStream {
             let variant = &variant.ident;
 
             if ident == "error" {
-                error.insert(variant, |_| panic!("Only one #[error] variant can be declared."));
+                error.insert_or(variant, |_| panic!("Only one #[error] variant can be declared."));
             }
 
             if ident == "end" {
-                end.insert(variant, |_| panic!("Only one #[end] variant can be declared."));
+                end.insert_or(variant, |_| panic!("Only one #[end] variant can be declared."));
             }
 
             if let Some(path) = value_from_attr("token", attr) {
