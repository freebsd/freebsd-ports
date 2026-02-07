--- cli/args/flags.rs.orig	2025-03-29 17:44:00 UTC
+++ cli/args/flags.rs
@@ -520,6 +520,14 @@ impl DenoSubcommand {
             os: "darwin".into(),
             cpu: "arm64".into(),
           },
+          "aarch64-unknown-freebsd" => NpmSystemInfo {
+            os: "freebsd".into(),
+            cpu: "arm64".into(),
+          },
+          "x86_64-unknown-freebsd" => NpmSystemInfo {
+            os: "freebsd".into(),
+            cpu: "x64".into(),
+          },
           "aarch64-unknown-linux-gnu" => NpmSystemInfo {
             os: "linux".into(),
             cpu: "arm64".into(),
@@ -1971,6 +1979,8 @@ On the first invocation of `deno compile`, Deno will d
           .long("target")
           .help("Target OS architecture")
           .value_parser([
+            "x86_64-unknown-freebsd",
+            "aarch64-unknown-freebsd",
             "x86_64-unknown-linux-gnu",
             "aarch64-unknown-linux-gnu",
             "x86_64-pc-windows-msvc",
