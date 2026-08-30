--- rust/bridge/shared/types/src/ffi/mod.rs.orig	2026-06-25 20:33:59 UTC
+++ rust/bridge/shared/types/src/ffi/mod.rs
@@ -79,8 +79,7 @@ impl<T> BorrowedMutableSliceOf<T> {
     }
 }
 
-/// A buffer of `length` elements of type `T`, allocated with the alignment of
-/// [`libc::max_align_t`].
+/// A buffer of `length` elements of type `T`, allocated with a fixed alignment.
 ///
 /// The number of bytes allocated is stored in `size_bytes`.
 ///
@@ -100,8 +99,13 @@ impl<T> OwnedBufferOfMaxAligned<T> {
 }
 
 impl<T> OwnedBufferOfMaxAligned<T> {
-    pub const ALIGNMENT: usize = std::mem::align_of::<libc::max_align_t>();
+    // A reasonable max alignment for most types we use. (We aren't using SIMD types here.)
+    // A const-time assertion will trip if this alignment isn't sufficient.
+    pub const ALIGNMENT: usize = 16;
     pub fn layout_for_count(count: usize) -> std::alloc::Layout {
+        const {
+            assert!(std::mem::align_of::<T>() <= Self::ALIGNMENT);
+        }
         std::alloc::Layout::array::<T>(count)
             .expect("valid layout")
             .align_to(Self::ALIGNMENT)
