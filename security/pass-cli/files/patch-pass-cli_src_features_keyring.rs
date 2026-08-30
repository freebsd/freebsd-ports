--- pass-cli/src/features/keyring.rs.orig	2026-07-26 12:15:02 UTC
+++ pass-cli/src/features/keyring.rs
@@ -89,6 +89,22 @@ fn init_linux_store() -> Result<()> {
     Ok(())
 }
 
+#[cfg(target_os = "freebsd")]
+fn init_freebsd_store() -> Result<()> {
+    info!("FreeBSD keyring: D-Bus backend requested");
+    let store = zbus_secret_service_keyring_store::Store::new().map_err(|e| {
+        anyhow::anyhow!(
+            "FreeBSD keyring: D-Bus secret service is unavailable or locked. \
+            Make sure your desktop session is unlocked and the Secret Service \
+            (e.g. GNOME Keyring) is running: {e}"
+        )
+    })?;
+    keyring_core::set_default_store(store);
+    info!("FreeBSD keyring: using zbus secret service (persistent)");
+
+    Ok(())
+}
+
 fn init_keyring_store() -> Result<()> {
     #[cfg(target_os = "macos")]
     {
@@ -106,6 +122,9 @@ fn init_keyring_store() -> Result<()> {
 
     #[cfg(target_os = "linux")]
     init_linux_store()?;
+
+    #[cfg(target_os = "freebsd")]
+    init_freebsd_store()?;
 
     Ok(())
 }
