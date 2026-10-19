--- src/main.rs.orig	2026-09-29 13:29:05 UTC
+++ src/main.rs
@@ -7,13 +7,24 @@ mod http;
 mod file;
 mod http;
 
+/// File recording the name of the configured zone. FreeBSD's tzsetup(8)
+/// keeps it in /var/db/zoneinfo (read back by tzsetup -r and freebsd-update);
+/// Debian and derivatives use /etc/timezone.
+#[cfg(target_os = "freebsd")]
+const TIMEZONE_NAME_PATH: &str = "/var/db/zoneinfo";
+#[cfg(not(target_os = "freebsd"))]
+const TIMEZONE_NAME_PATH: &str = "/etc/timezone";
+
+/// tzsetup(8) always writes /var/db/zoneinfo, so do the same on FreeBSD.
+const ALWAYS_WRITE_TIMEZONE_NAME: bool = cfg!(target_os = "freebsd");
+
 #[derive(Parser, Debug)]
 #[command(author, version, about, long_about = None)]
 struct Config {
     #[arg(
         short,
         long,
-        help = "print the timezone, but don't update /etc/timezone or /etc/localtime"
+        help = "print the timezone, but don't update the timezone name file or /etc/localtime"
     )]
     print_only: bool,
 
@@ -50,12 +61,12 @@ struct Config {
     #[arg(
         short,
         long,
-        help = "path to Debian timezone name file",
-        default_value = "/etc/timezone"
+        help = "path to timezone name file (/var/db/zoneinfo on FreeBSD, /etc/timezone on Debian)",
+        default_value = TIMEZONE_NAME_PATH
     )]
     debian_timezone_path: PathBuf,
 
-    #[arg(long, help = "create Debian timezone file even if it doesn't exist")]
+    #[arg(long, help = "create timezone name file even if it doesn't exist (always on FreeBSD)")]
     always_write_debian_timezone: bool,
 
     #[arg(
@@ -91,7 +102,7 @@ fn main() -> Result<()> {
     file::write_timezone(
         &tz,
         cfg.debian_timezone_path,
-        cfg.always_write_debian_timezone,
+        cfg.always_write_debian_timezone || ALWAYS_WRITE_TIMEZONE_NAME,
     )?;
     println!("Set system timezone to {tz}.");
 
