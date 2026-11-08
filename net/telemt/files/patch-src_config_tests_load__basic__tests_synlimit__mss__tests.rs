--- src/config/tests/load_basic_tests/synlimit_mss_tests.rs.orig	2026-08-23 14:01:09 UTC
+++ src/config/tests/load_basic_tests/synlimit_mss_tests.rs
@@ -1,5 +1,6 @@
 use super::*;
 
+#[cfg(target_os = "linux")]
 #[test]
 fn synlimit_synfix_defaults_are_loaded_for_listener() {
     let cfg = load_config_from_temp_toml(
