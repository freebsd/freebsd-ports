--- gossip/src/ping_pong.rs.orig	2026-04-14 19:36:20 UTC
+++ gossip/src/ping_pong.rs
@@ -94,7 +94,7 @@ impl<const N: usize> Signable for Ping<N> {
     }
 
     #[inline]
-    fn signable_data(&self) -> Cow<[u8]> {
+    fn signable_data(&self) -> Cow<'_, [u8]> {
         Cow::Borrowed(&self.token)
     }
 
@@ -140,7 +140,7 @@ impl Signable for Pong {
         self.from
     }
 
-    fn signable_data(&self) -> Cow<[u8]> {
+    fn signable_data(&self) -> Cow<'_, [u8]> {
         Cow::Owned(self.hash.as_ref().into())
     }
 
