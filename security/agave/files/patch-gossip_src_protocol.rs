--- gossip/src/protocol.rs.orig	2026-04-14 19:36:20 UTC
+++ gossip/src/protocol.rs
@@ -103,7 +103,7 @@ impl PruneData {
 }
 
 impl PruneData {
-    fn signable_data_without_prefix(&self) -> Cow<[u8]> {
+    fn signable_data_without_prefix(&self) -> Cow<'_, [u8]> {
         #[derive(Serialize)]
         struct SignData<'a> {
             pubkey: &'a Pubkey,
@@ -120,7 +120,7 @@ impl PruneData {
         Cow::Owned(serialize(&data).expect("should serialize PruneData"))
     }
 
-    fn signable_data_with_prefix(&self) -> Cow<[u8]> {
+    fn signable_data_with_prefix(&self) -> Cow<'_, [u8]> {
         #[derive(Serialize)]
         struct SignDataWithPrefix<'a> {
             prefix: &'a [u8],
@@ -199,7 +199,7 @@ impl Signable for PruneData {
         self.pubkey
     }
 
-    fn signable_data(&self) -> Cow<[u8]> {
+    fn signable_data(&self) -> Cow<'_, [u8]> {
         // Continue to return signable data without a prefix until cluster has upgraded
         self.signable_data_without_prefix()
     }
