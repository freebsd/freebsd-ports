--- src/hbbr.rs.orig	2023-03-29 16:43:49 UTC
+++ src/hbbr.rs
@@ -10,7 +10,7 @@ fn main() -> ResultType<()> {
     let _logger = Logger::try_with_env_or_str("info")?
         .log_to_stdout()
         .format(opt_format)
-        .write_mode(WriteMode::Async)
+        .write_mode(WriteMode::Direct)
         .start()?;
     let args = format!(
         "-p, --port=[NUMBER(default={RELAY_PORT})] 'Sets the listening port'
