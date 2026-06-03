--- votor/src/consensus_pool.rs.orig	2026-04-14 19:44:10 UTC
+++ votor/src/consensus_pool.rs
@@ -19,7 +19,7 @@ use {
         consensus_message::{Block, Certificate, CertificateType, ConsensusMessage, VoteMessage},
         vote::Vote,
     },
-    log::{error, trace},
+    log::trace,
     solana_clock::{Epoch, Slot},
     solana_epoch_schedule::EpochSchedule,
     solana_gossip::cluster_info::ClusterInfo,
