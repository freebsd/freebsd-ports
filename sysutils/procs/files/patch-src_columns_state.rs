This is upstream's fix.  To be removed at the next update.

--- src/columns/state.rs.orig	2024-10-23 10:22:18 UTC
+++ src/columns/state.rs
@@ -129,7 +129,7 @@ impl Column for State {
         if (flag & libc::P_SYSTEM as i64) != 0 || info.lock > 0 {
             state.push_str("L");
         }
-        if (cr_flags & bsd_kvm_sys::CRED_FLAG_CAPMODE) != 0 {
+        if (cr_flags & libc::KI_CRF_CAPABILITY_MODE as u32) != 0 {
             state.push_str("C");
         }
         if (kiflag & libc::KI_SLEADER as i64) != 0 {
