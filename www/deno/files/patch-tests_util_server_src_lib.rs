Fixes some tests by referencing the test binary.

Index: tests/util/server/src/lib.rs
--- tests/util/server/src/lib.rs.orig
+++ tests/util/server/src/lib.rs
@@ -227,7 +227,7 @@ pub fn std_file_url() -> String {
 }
 
 pub fn target_dir() -> PathRef {
-  let current_exe = std::env::current_exe().unwrap();
+  let current_exe = PathBuf::from("WRKDIR/target/release/blah/deno");
   let target_dir = current_exe.parent().unwrap().parent().unwrap();
   PathRef::new(target_dir)
 }
