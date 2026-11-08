--- src/ton_connect/derived.rs.orig	2026-09-30 18:17:05 UTC
+++ src/ton_connect/derived.rs
@@ -422,6 +422,27 @@ impl TonConnectDerivedSession {
         }))
     }
 
+    /// Decodes a `signData` cell by its TL-B schema for display.
+    ///
+    /// Pass the `schema` and `cell` of a `TonConnectSignDataPayload::Cell` exactly as received.
+    /// The result lists the fields of the schema's last declaration (the root constructor, whose
+    /// tag the cell must carry) in cell order, or reports the cell as not decodable when the
+    /// schema uses an unsupported construct or the cell does not match it; it is never a partial
+    /// list. Addresses are TEP-2 friendly, non-bounceable, and test-only on a testnet session.
+    /// Signing does not depend on this result.
+    #[must_use]
+    pub fn decode_sign_data_cell(
+        &self,
+        schema: String,
+        cell: String,
+    ) -> crate::TonConnectSignDataCellDecoding {
+        crate::ton_connect_tlb::decode_sign_data_cell(
+            &schema,
+            &cell,
+            self.network.as_str() == crate::Network::Testnet.global_id(),
+        )
+    }
+
     /// Encrypts the empty-object result of a dApp-initiated disconnect request.
     pub fn encrypt_disconnect_success(
         &self,
