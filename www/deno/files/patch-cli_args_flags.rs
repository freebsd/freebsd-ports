--- cli/args/flags.rs.orig	2026-07-01 13:28:43 UTC
+++ cli/args/flags.rs
@@ -2306,7 +2306,9 @@ Unless --reload is specified, this command will not re
     )
 }
 
-const SUPPORTED_OS: [&str; 5] = [
+const SUPPORTED_OS: [&str; 7] = [
+  "x86_64-unknown-freebsd",
+  "aarch64-unknown-freebsd",
   "x86_64-unknown-linux-gnu",
   "aarch64-unknown-linux-gnu",
   "x86_64-pc-windows-msvc",
