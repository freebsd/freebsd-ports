fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut config = prost_build::Config::new();

    if let Ok(protoc) = std::env::var("PROTOC") {
        config.protoc_executable(protoc);
    } else {
        let protoc = protoc_bin_vendored::protoc_bin_path()?;
        config.protoc_executable(protoc);
    }

    config.compile_protos(&["service.proto"], &["."])?;
    Ok(())
}
