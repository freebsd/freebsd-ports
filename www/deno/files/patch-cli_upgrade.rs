--- cli/upgrade.rs.orig	2020-07-22 16:15:41.99 UTC
+++ cli/upgrade.rs
@@ -35,6 +35,8 @@ const ARCHIVE_NAME: &str = "deno-x86_64-pc-windows-msv
 const ARCHIVE_NAME: &str = "deno-x86_64-apple-darwin.zip";
 #[cfg(target_os = "linux")]
 const ARCHIVE_NAME: &str = "deno-x86_64-unknown-linux-gnu.zip";
+#[cfg(target_os = "freebsd")]
+const ARCHIVE_NAME: &str = "deno-x86_64-unknown-freebsd.zip";
 
 async fn get_latest_version(client: &Client) -> Result<Version, ErrBox> {
   println!("Checking for latest version");
