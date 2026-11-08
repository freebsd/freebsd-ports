-- Allow the __int64_t type in bindgen-generated bindings on FreeBSD.
-- The FreeBSD headers expose __mbstate_t, which contains an __int64_t
-- field.  With __int64_t blocklisted, the generated bindings reference
-- an undefined type and compilation fails.
-- Upstream aws-lc-sys does not yet ship FreeBSD-specific bindings.
-- upstreamed: https://github.com/aws/aws-lc-rs/pull/1281

--- cargo-crates/aws-lc-sys-0.46.0/builder/sys_bindgen.rs.orig	2026-10-29 11:35:27.157758000 -0700
+++ cargo-crates/aws-lc-sys-0.46.0/builder/sys_bindgen.rs	2026-10-29 11:35:39.811268000 -0700
@@ -83,7 +83,7 @@

 // Includes implementation types behind the public aliases: bindgen can emit
 // dependencies of blocked items even when nothing uses them.
-const BLOCKED_TYPES: [&str; 20] = [
+const BLOCKED_TYPES: [&str; 19] = [
     "FILE",
     "fpos_t",
     "tm",
@@ -94,7 +94,6 @@
     "__va_list_tag",
     "__off_t",
     "__off64_t",
-    "__int64_t",
     "__darwin_off_t",
     "_IO_FILE",
     "_IO_marker",
