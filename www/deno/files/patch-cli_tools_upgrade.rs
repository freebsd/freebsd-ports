--- cli/tools/upgrade.rs.orig	2023-06-21 09:01:25 UTC
+++ cli/tools/upgrade.rs
@@ -376,6 +376,8 @@ pub async fn upgrade(
   flags: Flags,
   upgrade_flags: UpgradeFlags,
 ) -> Result<(), AnyError> {
+  #[cfg(target_os = "freebsd")]
+  bail!("Upgrades are not supported on FreeBSD.");
   let factory = CliFactory::from_flags(flags)?;
   let client = factory.http_client();
   let current_exe_path = std::env::current_exe()?;
