--- cli/args/flags.rs.orig	2026-09-17 12:50:50 UTC
+++ cli/args/flags.rs
@@ -136,6 +136,14 @@ pub fn npm_system_info(subcommand: &DenoSubcommand) ->
           os: "linux".into(),
           cpu: "x64".into(),
         },
+        "x86_64-unknown-freebsd" => NpmSystemInfo {
+          os: "freebsd".into(),
+          cpu: "x64".into(),
+        },
+        "aarch64-unknown-freebsd" => NpmSystemInfo {
+          os: "freebsd".into(),
+          cpu: "arm64".into(),
+        },
         "x86_64-pc-windows-msvc" => NpmSystemInfo {
           os: "win32".into(),
           cpu: "x64".into(),
