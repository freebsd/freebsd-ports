--- gossip/src/crds_value.rs.orig	2026-04-14 19:36:20 UTC
+++ gossip/src/crds_value.rs
@@ -41,7 +41,7 @@ impl Signable for CrdsValue {
         self.pubkey()
     }
 
-    fn signable_data(&self) -> Cow<[u8]> {
+    fn signable_data(&self) -> Cow<'_, [u8]> {
         Cow::Owned(serialize(&self.data).expect("failed to serialize CrdsData"))
     }
 
