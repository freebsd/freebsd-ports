--- src/update.rs.orig	2026-09-29 14:11:37 UTC
+++ src/update.rs
@@ -2112,6 +2112,13 @@ pub fn self_update(options: SelfUpdateOptions) -> Resu
 pub fn self_update(options: SelfUpdateOptions) -> Result<Version, String> {
     let channel = UpdateChannel::configured();
 
+    // Herdr publishes no FreeBSD binaries; the package manager owns the install.
+    if cfg!(target_os = "freebsd") {
+        return Err(
+            "self-update is disabled for FreeBSD package installs; run `pkg upgrade herdr`".into(),
+        );
+    }
+
     if is_homebrew_managed_install() {
         if channel == UpdateChannel::Preview {
             return Err(
@@ -2242,6 +2249,10 @@ pub fn auto_update(events: tokio::sync::mpsc::Sender<c
 /// Background update check: only surface availability and release notes.
 /// Runs in a background thread at startup.
 pub fn auto_update(events: tokio::sync::mpsc::Sender<crate::events::AppEvent>) {
+    // Herdr publishes no FreeBSD binaries; updates come from pkg(8).
+    if cfg!(target_os = "freebsd") {
+        return;
+    }
     crate::logging::update_check_started();
     if let Ok(version) = env::var(FAKE_UPDATE_VERSION_ENV) {
         let version = version.trim();
