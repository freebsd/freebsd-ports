--- src/config/tests/load_basic_tests/defaults_access_tests.rs.orig	2026-08-31 00:18:32 UTC
+++ src/config/tests/load_basic_tests/defaults_access_tests.rs
@@ -97,6 +97,7 @@ fn serde_defaults_remain_unchanged_for_present_section
         cfg.general.rpc_proxy_req_every,
         default_rpc_proxy_req_every()
     );
+    assert_eq!(cfg.general.data_path, Some(PathBuf::from("/var/db/telemt")));
     assert_eq!(cfg.general.beobachten_file, default_beobachten_file());
     assert_eq!(cfg.general.update_every, default_update_every());
     assert_eq!(cfg.server.listen_addr_ipv4, default_listen_addr_ipv4());
