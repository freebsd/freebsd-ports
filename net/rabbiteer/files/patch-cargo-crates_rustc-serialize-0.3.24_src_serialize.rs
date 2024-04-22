https://github.com/rust-lang-deprecated/rustc-serialize/commit/75ce92452a5f7c25a58fdea81e5f6f888630a2c9

--- cargo-crates/rustc-serialize-0.3.24/src/serialize.rs.orig	2024-02-10 11:58:37 UTC
+++ cargo-crates/rustc-serialize-0.3.24/src/serialize.rs
@@ -1152,7 +1152,7 @@ impl<'a, T: ?Sized> Decodable for Cow<'a, T>
     where T: ToOwned, T::Owned: Decodable
 {
     #[inline]
-    fn decode<D: Decoder>(d: &mut D) -> Result<Cow<'static, T>, D::Error> {
+    fn decode<D: Decoder>(d: &mut D) -> Result<Cow<'a, T>, D::Error> {
         Ok(Cow::Owned(try!(Decodable::decode(d))))
     }
 }
