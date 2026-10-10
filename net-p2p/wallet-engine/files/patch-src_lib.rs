--- src/lib.rs.orig	2026-09-30 18:17:05 UTC
+++ src/lib.rs
@@ -47,6 +47,7 @@ mod ton_connect;
 mod domain;
 mod engine;
 mod ton_connect;
+mod ton_connect_tlb;
 mod transport;
 mod types;
 mod wallet;
@@ -54,6 +55,9 @@ pub use ton_connect::*;
 pub use domain::*;
 pub use engine::{WalletClient, WalletPlatformHost};
 pub use ton_connect::*;
+pub use ton_connect_tlb::{
+    TonConnectSignDataCellDecoding, TonConnectSignDataCellFailure, TonConnectSignDataCellField,
+};
 pub use transport::*;
 pub use types::{
     Base64Hash, Base64HashError, Boc, BocError, NonEmptyString, NonEmptyStringError,
