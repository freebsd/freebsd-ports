Index: ext/node/ops/constant.rs
--- ext/node/ops/constant.rs.orig
+++ ext/node/ops/constant.rs
@@ -226,6 +226,13 @@ fn common_unix_fs_constants() -> FsConstants {
   }
 }
 
+#[cfg(target_os = "freebsd")]
+#[op2]
+#[serde]
+pub fn op_node_fs_constants() -> FsConstants {
+  common_unix_fs_constants()
+}
+
 #[cfg(target_os = "macos")]
 #[op2]
 #[serde]
