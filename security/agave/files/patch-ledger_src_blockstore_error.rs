--- ledger/src/blockstore/error.rs.orig	2026-04-14 19:25:34 UTC
+++ ledger/src/blockstore/error.rs
@@ -1,6 +1,6 @@
 //! The error that can be produced from Blockstore operations.
 
-use {agave_snapshots::hardened_unpack::UnpackError, log::*, solana_clock::Slot, thiserror::Error};
+use {agave_snapshots::hardened_unpack::UnpackError, solana_clock::Slot, thiserror::Error};
 
 #[derive(Error, Debug)]
 pub enum BlockstoreError {
