--- codex-rs/code-mode-protocol/build.rs.orig	2026-08-22 04:54:14 UTC
+++ codex-rs/code-mode-protocol/build.rs
@@ -5,7 +5,6 @@ fn main() -> Result<(), Box<dyn std::error::Error>> {
     println!("cargo:rerun-if-changed=src/grpc");
 
     let mut config = tonic_prost_build::Config::new();
-    config.protoc_executable(protoc_bin_vendored::protoc_bin_path()?);
     let proto_files = glob::glob("src/grpc/*.proto")?.collect::<Result<Vec<_>, _>>()?;
 
     tonic_prost_build::configure()
