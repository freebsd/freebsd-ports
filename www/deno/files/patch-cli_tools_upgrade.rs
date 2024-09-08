--- cli/tools/upgrade.rs.orig	2023-06-21 09:01:25 UTC
+++ cli/tools/upgrade.rs
@@ -427,6 +427,8 @@ pub async fn upgrade(
   flags: Arc<Flags>,
   upgrade_flags: UpgradeFlags,
 ) -> Result<(), AnyError> {
+  #[cfg(target_os = "freebsd")]
+  bail!("Upgrades are not supported on FreeBSD.");
   let factory = CliFactory::from_flags(flags);
   let http_client_provider = factory.http_client_provider();
   let client = http_client_provider.get_or_create()?;
