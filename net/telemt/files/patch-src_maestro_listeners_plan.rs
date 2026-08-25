--- src/maestro/listeners/plan.rs.orig	2026-08-23 14:01:09 UTC
+++ src/maestro/listeners/plan.rs
@@ -7,6 +7,7 @@ use crate::config::{
 };
 use crate::transport::ListenOptions;
 
+#[cfg(target_os = "linux")]
 use super::tcp_mss_runtime_profile;
 
 /// Immutable socket and connection policy for one listener endpoint.
@@ -53,6 +54,7 @@ pub(crate) fn listener_bind_plan(
                 .effective_client_mss(&config.server)
                 .map_err(|error| format!("invalid client MSS for listener {addr}: {error}"))?
         };
+        #[cfg(target_os = "linux")]
         let listener_bulk_mss = (listener.transport != ListenerTransport::Web)
             .then_some(bulk_client_mss)
             .flatten();
