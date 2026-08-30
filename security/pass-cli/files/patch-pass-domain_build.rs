--- pass-domain/build.rs.orig	2026-07-26 13:38:24 UTC
+++ pass-domain/build.rs
@@ -63,7 +63,6 @@ fn generate_proto(filename: &str, out_dir: PathBuf) {
 
     protobuf_codegen::Codegen::new()
         .protoc()
-        .protoc_path(&protoc_bin_vendored::protoc_bin_path().unwrap())
         .include(proto_dir)
         .input(proto_path)
         .out_dir(out_dir)
