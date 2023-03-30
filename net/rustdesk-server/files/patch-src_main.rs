--- src/main.rs.orig	2023-03-29 16:43:49 UTC
+++ src/main.rs
@@ -11,7 +11,7 @@ fn main() -> ResultType<()> {
     let _logger = Logger::try_with_env_or_str("info")?
         .log_to_stdout()
         .format(opt_format)
-        .write_mode(WriteMode::Async)
+        .write_mode(WriteMode::Direct)
         .start()?;
     let args = format!(
         "-c --config=[FILE] +takes_value 'Sets a custom config file'
