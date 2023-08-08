--- cli/tools/upgrade.rs.orig	2023-06-21 09:01:25.854955000 +0200
+++ cli/tools/upgrade.rs	2023-06-21 09:02:02.849893000 +0200
@@ -267,6 +267,8 @@ pub async fn upgrade(
   flags: Flags,
   upgrade_flags: UpgradeFlags,
 ) -> Result<(), AnyError> {
+   #[cfg(target_os = "freebsd")]
+   bail!("Upgrades are not supported on FreeBSD.");
   let factory = CliFactory::from_flags(flags).await?;
   let client = factory.http_client();
   let current_exe_path = std::env::current_exe()?;
